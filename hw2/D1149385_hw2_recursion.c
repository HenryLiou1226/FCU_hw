#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int climbStairs(int steps)//recursion
{
    if(steps==0)
        return 1;
    else if(steps==1)
        return 1;
    else
        return climbStairs(steps-1)+climbStairs(steps-2);//return the answer value
}
int main(void)
{
    int steps;
    while(scanf("%d",&steps) != EOF)
    {
        printf("%d\n",climbStairs(steps));
    }
}
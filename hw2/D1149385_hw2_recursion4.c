#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int climbStairs(int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    else
        return climbStairs(n-1)+climbStairs(n-2);
}
int main(void)
{
    int steps;
    while(scanf("%d",&steps) != EOF)
    {
        printf("%d\n",climbStairs(steps));
    }
}
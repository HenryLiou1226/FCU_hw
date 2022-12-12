#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int climbStairs(int steps)
{
    int odd = 1;//steps [1] = 1
    int even = 2;//steps [2] = 2
    if(steps>2)
    {
        for(int round = 3;round < steps+1;round++)
        {
            if(round%2==1)//odd round odd = odd + even
            {
                odd=odd+even;//[2n] = [2n-1] + [2n-2]
            }
            else//even round even = odd + even
            {
                even=even+odd;//[2n+1] = [2n] + [2n-1]
            }
        }
    }
    if(steps%2==1)
    {
        return odd;//return the answer value
    }
    else
    {
        return even;//return the answer value
    }
}
int main(void)
{
    int steps;
    while(scanf("%d",&steps) != EOF)
    {
        printf("%d\n",climbStairs(steps));
    }
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max = 2;
int a[46]={0};
int climbStairs(int n)
{
    a[1]=1;
    a[0]=1;
    a[2]=2;
    if(n>max)
    {
        for(int i = max+1;i < n+1;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        max = n;
    }
    return a[n];
}
int main(void)
{
    int steps;
    while(scanf("%d",&steps) != EOF)
    {
        printf("%d\n",climbStairs(steps));
    }
}
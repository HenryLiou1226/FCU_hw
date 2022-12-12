#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long a[46];
int t = 0;
int climbStairs(int n){
    if(t==0)
    {
        dd();
        t+=1;
    }
    return a[n];
}
void dd()
{
    a[0]=1;
    a[1]=1;
    for(int i = 2;i < 46;i++)
    {
        a[i]=a[i-1]+a[i-2];
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
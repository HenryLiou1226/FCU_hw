#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max = 2;
int Fibonacci_sequence[46]={0};//define a array to store the value
int climbStairs(int steps)
{
    Fibonacci_sequence[1]=1;
    Fibonacci_sequence[0]=1;
    Fibonacci_sequence[2]=2;
    if(steps>max)//if the request value larger then the max value,extend the array
    {
        for(int i = max+1;i < steps+1;i++)
        {
            Fibonacci_sequence[i]=Fibonacci_sequence[i-1]+Fibonacci_sequence[i-2];//store the value of Fibonacci_sequence into array
        }
        max = steps;
    }
    return Fibonacci_sequence[steps];//return the answer value
}
int main(void)
{
    int steps;
    while(scanf("%d",&steps) != EOF)
    {
        printf("%d\n",climbStairs(steps));
    }
}
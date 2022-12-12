#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long Fibonacci_sequence[46];//define a array to store the value
void array()
{
    Fibonacci_sequence[0]=1;
    Fibonacci_sequence[1]=1; 
    for(int i = 2;i < 46;i++)
    {
        Fibonacci_sequence[i]=Fibonacci_sequence[i-1]+Fibonacci_sequence[i-2];//store the value of Fibonacci_sequence into array
    }
}
int runtime = 0;
int climbStairs(int steps)
{
    if(runtime==0)//first time run the code,do function array() to store the value into Fibonacci_sequence array
    {
        array();
        runtime+=1;
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
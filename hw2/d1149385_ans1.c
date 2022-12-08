long long a[46];
int t = 0;
int climbStairs(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return climbStairs(n-1)+climbStairs(n-2);
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
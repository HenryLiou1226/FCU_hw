int climbStairs(int n){
    int a = 1;
    int b = 2;
    if(n>2)
    {
        for(int i = 3;i < n+1;i++)
        {
            if(i%2==1)
            {
                a=a+b;
            }
            else
            {
                b=b+a;
            }
        }
    }
    if(n%2==1)
    {
        return a;
    }
    else
    {
        return b;
    }
}
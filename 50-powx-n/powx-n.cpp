class Solution {
public:
    double fun(double x , long n  )
    {
        if(n==0)
        {
            return 1.0;
        }
        if(n==1) return x;
        if(n%2==0)
            return fun(x*x,n/2);
        return x*fun(x,n-1);
    }
    double myPow(double x, int n) {
        long temp = n;
        if(temp<0)
        {
            return 1.0/fun(x,-temp);
        }
        return fun(x,temp);

    }
};
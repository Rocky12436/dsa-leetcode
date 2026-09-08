class Solution {
public:
    unordered_map<int,int>dp;
    int fun(int n , int idx )
    {
        
        if (idx == n )
        {
            return 1;
        }
        if(idx>n)
        {
            return 0;
        }
        if(dp.find(idx)!=dp.end())
            return dp[idx] ;
        int ans1 = fun(n,idx+1);
        int ans2=fun(n,idx+2);
        int ans = ans1+ ans2;
        dp[idx]=ans;
        return ans;
    }
    int climbStairs(int n) {
        
        return fun(n,0);
    }
};
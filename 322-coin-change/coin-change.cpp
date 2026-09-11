class Solution {
public:
    int fun(vector<int>&a, int n , int i , int target , vector<vector<int>>&dp)
    {
        if(target == 0)
            return 0; 
        if(i == n)
            return 1e9;
        if(dp[i][target]!=-1)
            return dp[i][target];
        if(a[i]>target)
            return dp[i][target]=fun(a,n,i+1,target,dp);
        
        int c1 = 1+fun(a,n,i,target-a[i],dp);
        int c2 = fun(a,n,i+1,target,dp);
        return dp[i][target]=min(c1,c2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        

        int ans = fun(coins,n,0,amount,dp);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};
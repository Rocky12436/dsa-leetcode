class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;//transaction 
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        for(int i = 0 ; i<=k ; i++)
        {
            dp[n][i]=0;
        }
        for(int j = 0 ; j <=n ;j++)
        {
            dp[j][0]=0;
        }
        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = 1; j <=k ; j++)
            {
                if(j ==2 )
                {
                    dp[i][j] = max(dp[i+1][j-1] - prices[i],dp[i+1][k]);
                }
                else
                {
                    dp[i][j]=max(dp[i+1][2] + prices[i],dp[i+1][j]);
                }
            }
        }
        return dp[0][k];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        // target = 0
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        // i = n
        for(int target = 1; target <= amount; target++)
            dp[n][target] = 1e9;

        for(int i = n-1; i >= 0; i--)
        {
            for(int target = 1; target <= amount; target++)
            {
                if(coins[i] > target)
                {
                    dp[i][target] = dp[i+1][target];
                }
                else
                {
                    int c1 = 1 + dp[i][target-coins[i]];
                    int c2 = dp[i+1][target];

                    dp[i][target] = min(c1,c2);
                }
            }
        }

        if(dp[0][amount] == 1e9)
            return -1;

        return dp[0][amount];
    }
};
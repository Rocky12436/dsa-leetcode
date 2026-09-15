class Solution {
public:
    
    int minCost(int n, vector<int>& cuts) {
        
        int m = cuts.size();

        vector<int> c;
        c.push_back(0);

        for(int i = 0; i < m; i++)
        {
            c.push_back(cuts[i]);
        }

        c.push_back(n);

        sort(c.begin(), c.end());

        int s = c.size();

        vector<vector<int>> dp(s, vector<int>(s, 0));

        
        for(int len = 2; len < s; len++)
        {
            for(int i = 0; i + len < s; i++)
            {
                int j = i + len;

                dp[i][j] = INT_MAX;

                for(int k = i + 1; k < j; k++)
                {
                    int cost = c[j] - c[i];

                    int r = cost + dp[i][k] + dp[k][j];

                    dp[i][j] = min(dp[i][j], r);
                }
            }
        }

        return dp[0][s-1];
    }
};
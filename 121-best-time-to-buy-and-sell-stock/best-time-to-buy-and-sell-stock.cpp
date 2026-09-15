class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;

        vector<int> next(k+1, 0);
        vector<int> curr(k+1, 0);

        for(int i = n-1; i>=0; i--)
        {
            curr[0] = 0;

            for(int j = 1; j<=k; j++)
            {
                if(j == 2)
                {
                    curr[j] = max(next[j-1] - prices[i],
                                  next[j]);
                }
                else
                {
                    curr[j] = max(next[j-1] + prices[i],
                                  next[j]);
                }
            }

            next = curr;
        }

        return next[k];
    }
};
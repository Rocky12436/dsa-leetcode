class Solution {
public:

   
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0 ; i<n ; i++)
        {
            dp[i][i]=1;
        }
        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                if(s[i] == s[j])
                {
                    if(j == i+1)
                        dp[i][j] = 2;// ye edge case hai yaha apne ne j= i+1 liye hai isliye  j = i+1 hooga or idr aage -1 1 cut jaige 
                    else
                        dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
        
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = 0 ; 
        for(int i = 0  ; i< n ;i++)
        {
            total_sum+=nums[i];
        }
        int pos =(total_sum + target)/2;
        if(abs(target)>total_sum)
            return 0 ;
        if((total_sum + target) % 2 != 0)
            return 0;
        
        vector<vector<int>>dp(n+1,vector<int>(pos+1,-1));
        for(int i = 0 ; i<=pos ; i++)
        {
            dp[n][i]=0;
            dp[n][0]=1;
        }
        for(int i = n-1 ; i>=0;i--)
        {
            for(int j = 0 ; j<=pos;j++)
            {
                if(nums[i]>j)
                {
                    dp[i][j]=dp[i+1][j];
                }
                else
                {
                    dp[i][j]=dp[i+1][j-nums[i]] + dp[i+1][j];
                }
            }
        }
        return dp[0][pos];
    }
};
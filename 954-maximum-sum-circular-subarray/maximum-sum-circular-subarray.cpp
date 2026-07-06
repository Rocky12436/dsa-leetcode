class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = nums[0];
        int minsum = nums[0];
        int totalsum = 0 ;
        int currmax = 0 ;
        int currmin = 0;
        for(int i = 0 ; i<nums.size();i++)
        {
            currmax = max(nums[i] , nums[i]+currmax);
            maxsum = max(maxsum , currmax );
            currmin = min(nums[i],nums[i]+currmin);
            minsum = min(minsum,currmin);
            totalsum+=nums[i];
        }
        int normalsum = maxsum ;
        if(minsum == totalsum)
        {
            return normalsum;
        }
        int circularsum = totalsum - minsum ;
        return max(circularsum,normalsum) ;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int low = 0 ;
        int high = 0 ;
        int ans = 0 ;
        int onedelete =1 ;
        while(high<nums.size())
        {
            if(nums[high]==0)
            {
                onedelete --;
            }
            while(onedelete <0)
            {
                if(nums[low]==0)
                {
                    onedelete++;
                }
                low++;
            }
            ans = max(ans,high-low);
            high++;
        }
        return ans;
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxbest = nums[0];
        int minbest = nums[0];
        int ans = abs(nums[0]);
        for(int i = 1 ;i<nums.size();i++)
        {
           
            maxbest = (max(nums[i],maxbest+nums[i]));
            minbest = (min(nums[i],nums[i]+minbest));
        //    int  s1=abs(maxbest) ;
        //    int  s2=abs(minbest);
            ans = max(ans,max(abs(maxbest),abs(minbest)));


        }
        return ans ;
    }
};
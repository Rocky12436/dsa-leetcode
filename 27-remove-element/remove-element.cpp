class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int low = 0 ; 
        int high = 0 ;
        int n = nums.size();
        while(high<n)
        {
            if(nums[high]!=val)
            {
                nums[low]=nums[high];
                low++;
            }
            high++;
        }
        return low;
    }
};
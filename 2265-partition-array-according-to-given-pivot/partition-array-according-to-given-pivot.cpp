class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>less;
        vector<int>equal;
        vector<int>high;
        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i]<pivot)
                less.push_back(nums[i]);
            else if(nums[i]==pivot)
                equal.push_back(nums[i]);
            else{
                high.push_back(nums[i]);
            }
        }
        int idx = 0 ;
        for(int x : less)
        {
            nums[idx]=x;
            idx++;
        }
        for(int x : equal)
        {
            nums[idx]=x;
            idx++;
        }
        for(int x:high)
        {
            nums[idx]=x;
            idx++;
        }
        return nums;
    }
};
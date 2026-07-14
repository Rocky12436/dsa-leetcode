class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int i = 0 ; i<nums.size();i++)
        {
            f[nums[i]]++;
        }
        for(auto i : f)
        {
            int value = i.second;
            if(value > nums.size()/2)
            {
                return i.first;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0 ;
        int zero = 0 ;
        int one = 0 ;
        unordered_map<int,int>f;
        for(int i = 0 ; i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else{
                one++;
            }
            int diff = zero - one ; 
            if(diff == 0)
            {
                res = max(res,i+1);
                continue;
            }
            if(f.find(diff)==f.end())
            {
                f[diff] = i ;
            }
            else{
                int len = i - f[diff];
                res=max(res,len);
            }
           
        }
        return res;
    }
};
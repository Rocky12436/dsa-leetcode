class Solution {
public:
    void fun(int target,int k,int idx,vector<int>&dairy,vector<vector<int>>&ans)
    {
        //base case 
        if(k==0)
        {
            if(target==0)
            {
                ans.push_back(dairy);
                
            }
            return ;
        }
        for(int i = idx ; i<=9;i++)
        {
            if(i>target) break;
            dairy.push_back(i);
            fun(target-i,k-1,i+1,dairy,ans);
            dairy.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>dairy;
        vector<vector<int>>ans;
        fun(n, k ,1,dairy,ans);
        return ans;
    }
};
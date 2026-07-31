class Solution {
public:
    void fun(vector<int>& a,int n , int idx,vector<int>&dia,int sum ,vector<vector<int>>&res,int target)
    {
       if(idx==n)
       {
            if(sum==target)
            {
                res.push_back(dia);
               
            }
             return ;
        } 
        fun(a,n,idx+1,dia,sum,res,target);
        if(a[idx]+sum<=target)
        {
            dia.push_back(a[idx]);
            sum=sum+a[idx];
            fun(a,n,idx,dia,sum,res,target);
            dia.pop_back();
            sum=sum-a[idx];

        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>dairy;
        vector<vector<int>>res;
        int sum = 0 ;
        fun(candidates,candidates.size(),0,dairy,sum,res,target);
        return res;
    }
};
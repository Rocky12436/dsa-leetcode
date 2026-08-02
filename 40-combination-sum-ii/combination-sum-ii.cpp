class Solution {
public:
    void fun(vector<int>& a,int n , int idx,vector<int>&dia,int sum ,vector<vector<int>>&res,int target)
    {
       
       
            if(sum==target)
            {
                res.push_back(dia);
                return;
               
            }
            if(idx == n)
                return;
         
       for(int i =idx ;i<n;i++)
        {
            if(i > idx && a[i] == a[i - 1])
                continue;
            if(a[i]+sum<=target)
            {
                dia.push_back(a[i]);
                sum=sum+a[i];
                fun(a,n,i+1,dia,sum,res,target);
                dia.pop_back();
                sum=sum-a[i];

            }
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>dairy;
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        int sum = 0 ;
        fun(candidates,candidates.size(),0,dairy,sum,res,target);
        return res;
    }
};
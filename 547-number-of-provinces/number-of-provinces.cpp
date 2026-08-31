class Solution {
public:
    void dfs(vector<vector<int>>&a,int node , vector<int>&vis)
    {
        vis[node]=1;
        for(int j = 0 ; j<a.size();j++)
        {
            if(a[node][j] && vis[j]==0)
            {
                dfs(a,j,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0 ;
         int n = isConnected.size();
        vector<int>vis(n,0);
       
        for(int i = 0 ;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(isConnected,i,vis);
            }
        }
        return cnt;
    }
};
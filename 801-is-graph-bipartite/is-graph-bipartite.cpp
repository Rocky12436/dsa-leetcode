class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>&a, int node , int c , vector<int>&color)
    {
        color[node]=c;
        for(int i = 0 ; i<a[node].size();i++)
        {
            int neigh = a[node][i];
            if(color[neigh]!=-1 && color[neigh]==c)
            {
                res=false;
            }
            if(color[neigh]==-1)
            {
                dfs(a,neigh,1-c,color);
            }
        }
        return ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i = 0 ;i<n;i++)
        {
            if(color[i]==-1)
            {
                dfs(graph,i,0,color);
            }
        }
        return res;
    }
};
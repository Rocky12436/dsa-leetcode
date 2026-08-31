class Solution {
public:
    bool dfs(vector<vector<int>>&a,int node , int dest , vector<int>&vis)
    {
        vis[node]=1;
        if(node == dest)
            return true ;
        for(int j = 0 ; j<a[node].size();j++)
        {
            int neigh = a[node][j];
            if(vis[neigh]==0)
            {
                if(dfs(a,neigh,dest,vis))
                {
                    return true ;
                }
                
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i<edges.size();i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<int>vis(n,0);
        return dfs(adj,source,destination,vis);
        

    }
};
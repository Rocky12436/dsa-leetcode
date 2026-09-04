class Solution {
public:
    int Maxcycle = -1;
    void dfs(vector<int>&a, int node,vector<bool>&path,vector<bool>&vis,vector<int>&cycle)
    {
        vis[node]=1;
        path[node]=1;
        cycle.push_back(node);
         if(a[node]==-1)
         {
            path[node] = 0;
            cycle.pop_back();
            return;
        }    
        int neigh = a[node];
            if(vis[neigh]==1 && path[neigh]==1)
            {
                // wo dist nikalte apn
                for(int i = 0; i < cycle.size(); i++)
                {
                    if(neigh == cycle[i])
                    {
                        int len = cycle.size() - i;
                        Maxcycle=max(Maxcycle,len);
                        
                    }
                }
            }
           
            if(vis[neigh]==0)
            {
                dfs(a,neigh,path,vis,cycle);
            }
            path[node] = 0;
            cycle.pop_back();
       
        
            
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int>cycle;
        vector<bool>vis(n,0);
        vector<bool>path(n,0);
        for(int i = 0 ; i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(edges,i,path,vis,cycle);
            }
        }
        return Maxcycle;
        
    }
};
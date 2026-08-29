class Solution {
public:
    void dfs(vector<vector<int>>&a,vector<vector<int>>&res,int node,vector<int>path )
    {
        path.push_back(node);
        for(int i = 0 ;i<a[node].size();i++)
        {
            int neigh = a[node][i];
            

            if(neigh == a.size()-1)
            {
                path.push_back(neigh);
                res.push_back(path);
                path.pop_back();
            }
            if(neigh!=a.size()-1)
                dfs(a,res,neigh,path);
           

        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>path;
        dfs(graph,res,0,path);
        return res;

       
    }
};
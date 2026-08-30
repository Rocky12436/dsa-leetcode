class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>>rev(n);
        vector<int>degree(n,0);
        queue<int>q;
        vector<int>ans;
        for(int i = 0 ; i<n;i++)
        {
            degree[i]=g[i].size();
            for(int j = 0 ; j<g[i].size();j++)
            {
                int neigh = g[i][j];
                rev[neigh].push_back(i);
            }
           
        }
        for(int i = 0 ; i<n;i++)
            {
                if(degree[i]==0)
                    q.push(i);
            }
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(int i = 0 ;i<rev[node].size();i++)
                {
                    int prev = rev[node][i];
                    degree[prev]--;
                    if(degree[prev]==0)
                        q.push(prev);

                }
            }
        sort(ans.begin(),ans.end());
        return ans;


    }
};
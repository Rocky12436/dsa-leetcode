class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>a(n);
        vector<int>degre(n,0);
        for(int i = 0 ; i<prerequisites.size();i++)
        {
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];
            a[src].push_back(dest);
            degre[dest]++;
        }
        queue<int>q;
        for(int i = 0 ; i<n;i++)
        {
            if(degre[i]==0)
            {
                q.push(i);
            }
        }
        int count = 0 ;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(int j = 0 ; j<a[node].size();j++)
            {
                int neigh = a[node][j];
                degre[neigh]--;
                if(degre[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
        if(count == n )
            return true;
        return false;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>a(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i = 0 ; i<prerequisites.size();i++)
        {
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];
            a[dest].push_back(src);
            indegree[src]++;
        }
        queue<int>q;
        for(int i = 0 ; i<numCourses;i++)
        {
            if(indegree[i]==0)

            {
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int j = 0 ; j<a[node].size();j++)
            {
                int neigh = a[node][j];
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
        if(res.size() != numCourses)
        {
            return {};
        }
        return res;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>a(n+1);
        for(int i = 0 ; i<times.size();i++)
        {
            int s = times[i][0];
            int di = times[i][1];
            int w = times[i][2];
            a[s].push_back({di,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d>dis[node])
                continue;
            for(int j =0;j<a[node].size();j++)
            {
                int neigh = a[node][j].first;
                int wt = a[node][j].second;
                if(d+wt<dis[neigh])
                {
                    dis[neigh]=wt+d;
                    pq.push({wt+d,neigh});
                }

            }
            

        }
        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dis[i] == INT_MAX)
                return -1;

            ans = max(ans, dis[i]);
        }

        return ans;
    }
};
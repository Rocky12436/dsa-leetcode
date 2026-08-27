class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>a(n);
        for(int i = 0 ; i<flights.size();i++)
        {
            int s = flights[i][0];
            int di = flights[i][1];
            int w = flights[i][2];
            a[s].push_back({di,w});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<vector<int>>dis(n,vector<int>(k+2,INT_MAX));
        dis[src][0]=1;
        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int cost = p.first;
            int node = p.second.first;
            int stop = p.second.second;
            if(node==dst)
            {
                return cost;
            }
            if(stop>k)
                continue;
            for(int j= 0 ; j<a[node].size();j++)
            {
                int neigh = a[node][j].first;
                int wt = a[node][j].second;

                int newcost = wt+cost;
                int newstop = stop+1;
                if(newcost<dis[neigh][newstop])
                {
                    dis[neigh][newstop]=newcost;
                    pq.push({newcost,{neigh,newstop}});
                }
            }
        }
        
        
        
        return -1;
    }
};
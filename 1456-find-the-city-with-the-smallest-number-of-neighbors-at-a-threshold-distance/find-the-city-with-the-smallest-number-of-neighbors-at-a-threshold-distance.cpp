class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = -1;
        int mincount = 1e9;
        for(int src = 0 ; src< n ; src++ )
        {
            vector<int>res(n,1e9);
            res[src]=0;
            for(int i = 0 ; i<n-1;i++)
            {
                for(int j = 0 ; j<edges.size();j++)
                {
                    int s = edges[j][0];
                    int d = edges[j][1];
                    int wt = edges[j][2];
                    if(res[s]!=1e9 && res[d]>res[s]+wt)
                    {
                        res[d]=res[s]+wt;
                    }
                    if(res[d] != 1e9 && res[s] > res[d] + wt)
                    {
                        res[s] = res[d] + wt;
                    }
                }
            }
            int count = 0 ;
            for(int i = 0 ; i< n ; i++)
            {
                if(i!=src && res[i]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<= mincount)
            {
                mincount=count;
                ans = src;

            }
        }
        return ans;
    }
};
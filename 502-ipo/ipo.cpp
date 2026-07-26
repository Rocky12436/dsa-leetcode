class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>proj;
        for(int i = 0 ; i<n;i++)
        {
            proj.push_back({capital[i],profits[i]});

        }
        sort(proj.begin(),proj.end());
        priority_queue<int>pq;
        int indx=0;
        while(k--)
        {
            while(indx<n)
            {
                if(proj[indx].first>w)
                {
                    break;
                } 
                    
                pq.push(proj[indx].second);
                indx++;

            }
            if(pq.empty())
            {
                return w;
            }
            
            w=w+pq.top();
            pq.pop();
           
        }
        return w;
    }
};
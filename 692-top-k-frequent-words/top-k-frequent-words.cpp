class Solution {
public:
    struct cmp {
        bool operator() (pair<string,int>&a,pair<string,int>&b)
        {
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            return a.second>b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>map;
        for(int i = 0 ; i<words.size();i++)
        {
            map[words[i]]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>pq;
        for(auto i : map)
        {
            string w = i.first;
            int freq = i.second;
            pair<string,int>curr={w,freq};
            if(pq.size()<k)
            {
                pq.push(curr);
                continue;
            }
            else if (curr.second>pq.top().second || (curr.second == pq.top().second &&
                     curr.first < pq.top().first))
            {
                pq.pop();
                pq.push(curr);
            }
            
        }
        vector<string>ans;
            while(!pq.empty())
            {
                ans.push_back(pq.top().first);
                pq.pop();
            }
            reverse(ans.begin(),ans.end());
        return ans;
    }
};
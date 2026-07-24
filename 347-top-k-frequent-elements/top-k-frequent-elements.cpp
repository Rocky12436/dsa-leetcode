class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;   // Min heap based on frequency
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;   // number -> frequency

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        // Insert into heap
        for (auto i : mp) {
            int ele = i.first;
            int  freq = i.second;
            pair<int,int>curr={freq,ele};   // {frequency, number}

            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }
            if(curr.first<pq.top().first)
            {
                continue;
            }
            pq.pop();
            pq.push(curr);
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);   // Take the number
            pq.pop();
        }

        return ans;
    }
};
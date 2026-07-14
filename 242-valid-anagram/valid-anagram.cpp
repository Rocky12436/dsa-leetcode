class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        if(s.size() != t.size())  
            return false;
        for(int i = 0 ;i<t.size();i++)
        {
            need[t[i]]++;
        }
        for(int i = 0 ;i <s.size();i++)
        {
            have[s[i]]++;
        }
        for(auto i: need )
        {
            char c = i.first;
            int fneed=i.second;
            if(have[c]<fneed)
            {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mpp;

        for(int i = 0; i < t.size(); i++)
        {
            if(i < s.size())
                mpp[s[i]]--;

            mpp[t[i]]++;
        }

        for(auto it : mpp)
        {
            if(it.second == 1)
                return it.first;
        }

        return ' ';
    }
};
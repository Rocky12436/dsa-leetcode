class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        
        for(int i = 0 ; i<ransomNote.size();i++)
        {
            need[ransomNote[i]]++;
        }
        for(int i = 0 ; i<magazine.size();i++)
        {
            have[magazine[i]]++;
        }
        for(auto i : need)
            {
                char c = i.first;
                int fneed = i.second;
              
                if(have[c]<fneed)
                {
                    return false;
                }
            }
        return true;
    }
};
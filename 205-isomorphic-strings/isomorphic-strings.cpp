class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>f;
        unordered_map<char,char>g;
        for(int i = 0 ; i<s.size();i++)
        {
            if(f.count(s[i])&&f[s[i]] !=t[i])
            {
                return false;
            }
            if(g.count(t[i]) && g[t[i]] !=s[i])
            {
                return false;
            }
            f[s[i]] = t[i];
            g[t[i]] = s[i];
        }
        return true;
       
    }
};
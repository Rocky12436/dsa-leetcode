class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        for(int i = 0 ; i<s.size();i++)
        {
            f[s[i]]++;
        }
        bool odd = false;
        int res = 0 ;
        for(auto i : f)
        {
            int value = i .second;
            if(value%2==0)
            {
               res+=value; 
            }
            else
            {
                odd = true;
                res += value - 1;
            }
           
        }
        if(odd)
            return res + 1;
        return res;
    }
};
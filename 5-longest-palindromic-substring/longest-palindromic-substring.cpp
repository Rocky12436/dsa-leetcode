class Solution {
public:
    int fun(string s , int left , int right)
    {
        while(left>= 0 && right<s.size() && s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        
        int n = s.size();
        int start = 0 ;
        int maxlen = 1;
        for(int i = 0 ; i<n;i++)
        {
            int odd = fun(s,i,i);
            int even = fun(s,i,i+1);
            int len = max(odd,even);
            if(len>maxlen)
            {
                maxlen=len;
                start = i - (len -1 )/2;
            }
                
        }
        return s.substr(start, maxlen);
    }
};
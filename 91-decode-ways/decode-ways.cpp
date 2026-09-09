class Solution {
public:
    int fun(string s , int n , int idx , vector<int>&dp)
    {
        if(idx == n)
            return 1;
        if(s[idx]=='0')
            return 0 ; 
        if(dp[idx]!=-1)
            return dp[idx];
        int count = fun(s,n,idx+1,dp);
        if(idx+1<n)
        {
            string temp = s.substr(idx,2);
            int num = stoi(temp);
            if(num>= 10 && num<=26)
            {
                count=count + fun(s,n,idx+2,dp);
            }
        }
        return dp[idx]=count;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return fun(s,n,0,dp);
    }
};
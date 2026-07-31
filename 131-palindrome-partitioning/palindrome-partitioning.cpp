class Solution {
public:
    bool check(string &s,int l , int h)
    {
        while(l<h)
        {
            if(s[l++]!=s[h--])
            {
                return false;
            }
        }
       
        return true;
        
    }
    void fun(string &s , int idx,int n , vector<string>&copy,vector<vector<string>>&res)
    {
        if(idx==n)
        {
            res.push_back(copy);
            return ;
        }
        for(int i = idx ; i<s.size();i++)
        {
            if(check(s,idx,i))
            {
                copy.push_back(s.substr(idx,i-idx+1));
                fun(s,i+1,n,copy,res);
                copy.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string>copy;
        vector<vector<string>>res;
        fun(s,0,s.size(),copy,res);
        return res;
    }
};
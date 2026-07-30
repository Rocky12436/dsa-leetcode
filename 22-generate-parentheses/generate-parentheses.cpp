class Solution {
public:
    void fun(int open , int close , int n , string&temp,vector<string>&res)
    {
        if(open == n && close == n )
        {
            res.push_back(temp);
            return;
        }
        //open
        if(open<n)
        {
            temp.push_back('(');
            fun(open+1,close,n,temp,res);
            temp.pop_back();

        }
        if(close<open)
        {
            temp.push_back(')');
            fun(open,close+1,n,temp,res);
            temp.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        int close=0;
        int open=0;
        vector<string>ans;
        string temp ="";
        fun(open,close,n,temp,ans);
        return ans;

    }
};
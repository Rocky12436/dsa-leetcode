class Solution {
public:
void fun(string &s,int indx,int n ,string &dairy,vector<string>&res)
{
    unordered_map<char,string>f;
    f['2'] = "abc";
    f['3'] = "def";
    f['4'] = "ghi";
    f['5'] = "jkl";
    f['6'] = "mno";
    f['7'] = "pqrs";
    f['8'] = "tuv";
    f['9'] = "wxyz";
    if(indx==n)
    {
        res.push_back(dairy);
        return ;
    }
    string choises=f[s[indx]];
    for(int j=0;j<choises.size();j++)
    {
        dairy.push_back(choises[j]);
        fun(s,indx+1,n,dairy,res);
        dairy.pop_back();
    }
    return ;
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        string dairy="";
        vector<string>ans;
       
        fun(digits,0,digits.size(),dairy,ans);
        return ans;
    }
};
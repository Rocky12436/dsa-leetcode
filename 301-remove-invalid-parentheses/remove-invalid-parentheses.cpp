class Solution {
public:
    bool isValid(string s )
    {
        int count = 0 ;
        for(int i =0 ; i<s.size();i++)
        {
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')')
            {
                if(count==0)
                    return false;
                count--;
            }

        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<string>ans;
        set<string>vis;
        queue<string>q;
        q.push(s);
        vis.insert(s);
        bool found = false;
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            
            
                
                if(isValid(curr))
                {
                    ans.push_back(curr);
                    found = true;
                }
                if(found)
                    continue;
                for(int i = 0 ; i<curr.size();i++)
                {
                    if(curr[i]!='(' && curr[i]!=')')
                        continue;
                    string temp = curr;
                    temp.erase(i,1);
                    if(vis.find(temp)==vis.end())
                    {
                        vis.insert(temp);
                        q.push(temp);
                    }

                }
            

        }
        return ans;
    }
};
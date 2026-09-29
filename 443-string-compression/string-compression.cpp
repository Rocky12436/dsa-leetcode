class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0 ;
        int j = 1 ;
        int write = 0 ;
        while(i<n)
        {
            if(j<n && chars[i]==chars[j])
            {
                j++;
            }
            else{
                int count = j -i ;
                chars[write]=chars[i];
                write++;
                if(count>1)
                {
                    string num = to_string(count);
                    for(int i = 0 ; i<num.size();i++)
                    {
                        chars[write]=num[i];
                        write++;
                    }

                }
                i=j;
                j++;
            }
        }
        return write;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m1;
        map<char,int>m2;
        for(int i = 0 ; i<s1.size();i++)
        {
            m1[s1[i]]++;
        }
        
        int k = s1.size();
        int low = 0;                 
        int high = 0;
        while(high<=s2.size())
        {
            m2[s2[high]]++;
            if(high - low + 1 ==k)
            {
                if(m1==m2)
                    return true;
                m2[s2[low]]--;
                if(m2[s2[low]]==0)
                {
                    m2.erase(s2[low]);
                }
                low++;
            }
            high++;
        }

    return false;
    }
};
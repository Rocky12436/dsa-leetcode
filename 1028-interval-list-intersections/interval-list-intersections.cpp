class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i = 0 ;
        int j = 0 ;
        vector<vector<int>>ans;
        while(i<a.size() && j<b.size())
        {
            int start1=a[i][0];
            int end1=a[i][1];
            int start2=b[j][0];
            int end2=b[j][1];
            if(start1<=start2)
            {
               if(end1>=start2)
               {
                int s = max(start1,start2);
                int q = min(end1,end2);
                ans.push_back({s,q});
               }
            }
            else
            {
                if(end2>=start1)
                {
                    int s = max(start1,start2);
                    int q = min(end1,end2);
                    ans.push_back({s,q});
                }
            }
            if(end1<=end2)
            {
                i++;
            }
            else{
                j++;
            }

        }
        return ans;
        
    }
};
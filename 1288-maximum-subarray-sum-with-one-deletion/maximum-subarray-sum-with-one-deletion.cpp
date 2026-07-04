class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodel = arr[0];
        int onedel =    INT_MIN ;
        int ans = arr[0];
        for(int i = 1 ;i<arr.size();i++)
        {
            int prevnodel = nodel;
            int prevonedel = onedel;
            nodel = max(prevnodel + arr[i],arr[i]);
            int v2;
            if(prevonedel == INT_MIN)
            {
                v2 = arr[i];
            }
            else {
                v2 = prevonedel + arr[i];
            }
            onedel = max (v2,prevnodel);
            ans = max(ans , max(nodel,onedel));
        }
        return ans ; 
    }
};
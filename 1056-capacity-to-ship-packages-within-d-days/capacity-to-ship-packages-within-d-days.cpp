class Solution {
public:
    bool possible(vector<int>&a,long long  guess,int days)
    {
        int day=1;
        int load = 0 ;
        for(int i = 0 ; i<a.size();i++ )
        {
            if(load+a[i]<=guess)
            {
                load=load+a[i];
            }
            else
            {
                day++;
                load=a[i];
            }
            if(day>days)
            {
                return false;
            }
        }
        return true ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long  low = *max_element(weights.begin(),weights.end());
        long long  high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(low<=high)
        {
            long long mid = low +(high-low)/2;
            if(possible(weights,mid,days))
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
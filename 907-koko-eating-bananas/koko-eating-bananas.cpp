class Solution {
public:
    long long  hours(vector<int>&a,int n , int guess)
    {
        long long h = 0 ;
        for(int i = 0 ; i<n;i++)
        {
            h = h + a[i]/guess;
            if(a[i]%guess!=0)
            {
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1 ;
        long res =-1;
        int high= *max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            long long  hi = hours(piles,n,mid);
            if(hi>h)
            {
                low = mid +1;
            }
            else{
                res=mid;
                high = mid -1;
            }
        }
        return res;
    }
};
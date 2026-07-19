class Solution {
public:
    int mySqrt(int x) {
        long long  low = 0 ;
        long long  high = x;
        
        int ans = 1;
        while(low<=high)
        {
            long long  mid = low + (high - low )/2;
            if(mid*mid>x)
            {
                high = mid -1;
            }
            else if(mid*mid<x)
            {
                ans = mid;
                low=mid+1;
            }
            if(mid*mid==x) return mid;
        }
        return ans;
    }
};
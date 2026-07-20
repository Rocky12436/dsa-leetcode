class Solution {
public:
    bool boolday(vector<int>&arr,int guess,int m , int k )
    {
        int flower=0;
        int boucket=0;
        for(int i = 0 ; i<arr.size();i++)
        {
            if(arr[i]<=guess)
            {
                flower++;
                if(flower==k)
                {
                    boucket++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
        }
        return boucket>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;
        long long  low = *min_element(bloomDay.begin(),bloomDay.end());
        long long  high = *max_element(bloomDay.begin(),bloomDay.end());

        int res=-1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            if(boolday(bloomDay,mid,m,k))
            {
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};
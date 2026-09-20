class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0 ;
        int tenth = 0 ;
        for(int i = 0 ; i<n;i++)
        {
            
            int money = bills[i];
            if(money==5)
            {
                five ++;
            }
            else if ( money == 10)
            {
                if(five == 0)
                {
                    return 0;
                }
                five--;
                tenth ++;
            }
            else if(money ==20){
                if(tenth >0)
                {
                    tenth -- ;
                    if(five == 0)
                        return 0;
                    five --;
                }
                else{
                    if(five<3)
                    {
                        return false;
                    }
                    five = five -3;
                }
            }
        }
        return true ;
    }
};
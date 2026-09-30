class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0 ; 
        int j = tokens.size()-1;
        int score = 0 ;
        int ans = 0 ;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power = power - tokens[i];
                score++;
                i++;
                ans = max(ans,score);
            }
            else if(score>0)
            {
                power = power + tokens[j];
                score--;
                j--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
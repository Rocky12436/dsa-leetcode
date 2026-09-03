class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(int i = 0 ; i<wordList.size();i++)
        {
            st.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        if(st.find(endWord)==st.end())
            return 0;
        while(!q.empty())
        {
            pair<string,int>p=q.front();
            q.pop();
            string word = p.first;
            int dis = p.second;
            for(int i= 0 ; i<word.size();i++)
            {
                char orig= word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        if(word == endWord)
                            return dis + 1;
                        q.push({word,dis+1});
                        st.erase(word);
                    }
                }
                word[i] = orig;
            }
        }
        return 0 ;
        
    }
};
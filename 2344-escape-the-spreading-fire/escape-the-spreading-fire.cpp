class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    const int INF = 1e9;
    int Maxtime = -1;
    bool valid(int i , int j , int n , int m )
    {
        if(i<0 || i>= n || j<0 || j>= m)
            return false;
        return true ;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1)
            return 1e9;
        vector<vector<int>>fire(n,vector<int>(m,INF));
        queue<pair<pair<int,int>,int>>firewala;
        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                if(grid[i][j]==1)
                {
                    fire[i][j]=0;
                    firewala.push({{i,j},0});
                }
            }
        }
        while(!firewala.empty())
        {
            pair<pair<int,int>,int>p=firewala.front();
            firewala.pop();
            int r = p.first.first;
            int c = p.first.second;
            int time = p.second;
            for(int k = 0 ; k<4 ; k++)
            {
                int row = r + x[k];
                int col = c + y[k];
                int new_time = time+1;
                if(valid(row,col,n,m) && grid[row][col]!=2 && fire[row][col]==INF)
                {
                    fire[row][col]=new_time;
                    firewala.push({{row,col},new_time});
                }
            }
        }
        int low = 0 ; 
        int high = 1e9; 
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            vector<vector<int>>vis(n,vector<int>(m,0));
            if(fire[0][0] != INF && mid >= fire[0][0])
            {
                high = mid-1;
                continue;
            }
            queue<pair<pair<int,int>,int>>person;
            person.push({{0,0},mid});
            vis[0][0]=1;
            bool possible = false;
            while(!person.empty())
            {
                pair<pair<int,int>,int>p=person.front();
                person.pop();
                int r = p.first.first;
                int c = p.first.second;
                int currtime = p.second;
                for(int k = 0 ; k<4 ; k++)
                {
                    int row = r + x[k];
                    int col = c + y[k];
                    if(valid(row,col,n,m) && grid[row][col]==0 && vis[row][col]==0)
                    {
                        int time = currtime + 1;
                        if(row == n-1 && col == m-1)
                        {
                            if(fire[row][col] == INF || time <= fire[row][col])
                            {
                                possible = true ;
                                break;
                            }
                            else
                            {
                                continue;
                            }   
                        }
                        // normal cell
                        if(fire[row][col] != INF && time >= fire[row][col])
                        {
                            continue;
                        }
                        vis[row][col]=1;
                        person.push({{row,col},time});
                    }
                }
                if(possible)
                    break;
            }
            if(possible)
            {
                low = mid +1;
                Maxtime = mid ;
            }
            else{
                high = mid -1 ;
            }

        }
        return Maxtime;
        
    }
};
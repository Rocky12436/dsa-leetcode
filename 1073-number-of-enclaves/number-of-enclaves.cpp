class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool valid(int i , int j ,int n , int m)
    {
        if(i<0 || i>= n || j<0 || j>=m)
            return false;
        return true;
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i = 0 ; i<m ; i++)
        {
            if(grid[0][i]==1)
            {
                q.push({0,i});
                vis[0][i]=1;
            }
        }
        for(int i = 0 ; i<n;i++)
        {
            if(grid[i][0]==1)
            {
                vis[i][0]=1;
                q.push({i,0});
            }
        }
        for(int i = 0 ; i <n ; i++)
        {
            if(grid[i][m-1]==1)
            {
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int i = 0 ; i<m ; i++)
        {
            if(grid[n-1][i]==1)
            {
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int r = p.first;
            int c =p.second;
            for(int k = 0 ; k<4 ;k++)
            {
                int row = r + x[k];
                int col = c + y[k];
                if(valid(row,col,n,m) && grid[row][col]==1 && vis[row][col]==0)
                {
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j] == 1 && vis[i][j]==0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
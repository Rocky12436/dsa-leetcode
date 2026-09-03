class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool valid(int i , int j , int n ,int m )
    {
         if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }   
    void dfs(vector<vector<int>>&a,int n ,int m , int i , int j , vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        for(int k = 0 ; k<4 ; k ++)
        {
            int row = i + x[k];
            int col = j + y[k];
            if(valid(row,col,n,m) && vis[row][col]==0 && a[row][col]==0)
            {
                vis[row][col]=1;
                dfs(a,n,m,row,col,vis);
            }
        }
        return ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0 ;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ; i< m ; i++)
        {

            if(grid[0][i] == 0 && vis[0][i] == 0)
            {
                dfs(grid, n, m, 0, i, vis);
            }
            if(grid[n-1][i]==0 && vis[n-1][i]==0)
            {
                dfs(grid, n, m, n-1, i, vis);
            }
        }
        for(int i = 0 ; i<n;i++)
        {
            if(grid[i][0] == 0 && vis[i][0] == 0)
            {
                
                dfs(grid, n, m, i, 0, vis);
            }
            if(grid[i][m-1]==0 && vis[i][m-1]==0)
            {
            
                dfs(grid, n, m, i, m-1, vis);
            }
        }
        for(int i = 0 ; i< n ;i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                if(grid[i][j]==0 && vis[i][j]==0)
                {
                        
                    
                    dfs(grid,n,m,i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int numEnclaves(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<int,int>> q;

        
        for(int j = 0; j < m; j++)
        {
            if(grid[0][j] == 1) q.push({0,j}), vis[0][j] = 1;
            if(grid[n-1][j] == 1) q.push({n-1,j}), vis[n-1][j] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 1 && !vis[i][0])
                q.push({i,0}), vis[i][0] = 1;

            if(grid[i][m-1] == 1 && !vis[i][m-1])
                q.push({i,m-1}), vis[i][m-1] = 1;
        }

        
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int row = r + x[k], col = c + y[k];

                if(valid(row,col,n,m) && grid[row][col] == 1 && !vis[row][col])
                {
                    vis[row][col] = 1;
                    q.push({row,col});
                }
            }
        }

        
        int cnt = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1 && !vis[i][j])
                    cnt++;

        return cnt;
    }
};
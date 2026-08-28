class Solution {
public:
    int x[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int y[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    bool valid(int i , int j , int n , int m )
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true ;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        vector<vector<int>>res(n,vector<int>(m));
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        res[0][0]=1;
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            for(int k = 0 ;k<8;k++)
            {
                int r = row + x[k];
                int c = col + y[k];
                if(row == n-1 && col == m-1)
                return res[row][col];

                if(valid(r,c,n,m) && grid[r][c]==0 && vis[r][c]!=1)
                {
                    vis[r][c]=1;
                    q.push({r,c});
                    res[r][c] = res[row][col] + 1;
                }
            }

        }
        return -1;

    }
};
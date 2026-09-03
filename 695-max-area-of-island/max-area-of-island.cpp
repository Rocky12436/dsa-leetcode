class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool valid(int i , int j , int n , int m )
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int dfs(vector<vector<int>>&a,int n ,int m , int i , int j,vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        int cnt = 1;
        for(int k = 0 ; k<4 ; k++)
        {
            int row = i + x[k];
            int col = j +y[k];
            if(valid(row,col,n,m) && vis[row][col]==0 && a[row][col]==1)
            {
                vis[row][col]=1;
                cnt +=dfs(a,n,m,row,col,vis); 
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ;i<n ; i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int area = dfs(grid,n,m,i,j,vis);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
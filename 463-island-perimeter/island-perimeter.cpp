class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool valid(int i , int j , int n ,int m )
    {
        if(i<0|| i>= n || j<0 || j>=m)
            return false;
        return true ;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int ans = 0 ;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=true;
                    while(!q.empty())
                    {
                        pair<int,int>p=q.front();
                        q.pop();
                        int r = p.first;
                        int c = p.second;
                        for(int k = 0 ; k<4;k++)
                        {
                            int row = r +x[k];
                            int col = c +y[k];
                            if(!valid(row,col,n,m))
                            {
                                ans++;
                            }
                            else if(grid[row][col]==0)
                            {
                                ans++;
                            }
                            else if(vis[row][col]==false)
                            {
                                vis[row][col]=true;
                                q.push({row,col});
                            }
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;

    }
};
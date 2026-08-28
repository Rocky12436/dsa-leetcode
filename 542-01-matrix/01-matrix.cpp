class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool valid(int i ,int j , int n , int m )
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        queue<pair<int,int>> q;
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i = 0 ;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            for(int k = 0 ;k<4;k++)
            {
                int r = row + x[k];
                int c = col + y[k];
                if(valid(r,c,n,m) && vis[r][c]!=1)
                {
                    vis[r][c]=1;
                    q.push({r,c});
                    res[r][c] = res[row][col] + 1;
                }
            }

        }
        return res;
    }
};
class Solution {
public:
    int x[4]= {1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool valid (int i , int j , int n , int m )
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false ;
        return true ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>visp(n,vector<int>(m,0));
        vector<vector<int>>visa(n,vector<int>(m,0));
        vector<vector<int>>res;
        queue<pair<int,int>>qp;
        queue<pair<int,int>>qa;
        for(int i = 0 ; i <m;i ++)
        {
            qp.push({0,i});
            visp[0][i]=1;
        }
        for(int i = 0 ; i<n;i++)
        {
            qp.push({i,0});
            visp[i][0]=1;
        }
        for(int j = 0 ; j<n;j++)
        {
            qa.push({j,m-1});
            visa[j][m-1]=1;
        }
        for(int j = 0 ; j<m;j++)
        {
            qa.push({n-1,j});
            visa[n-1][j]=1;
        }
        while(!qa.empty())
        {
            
            pair<int,int>atlantic=qa.front();
            qa.pop();
            int a_r = atlantic.first;
            int a_c = atlantic.second;
            for(int k = 0 ; k<4 ; k++)
            {
                int row = a_r + x[k];
                int col = a_c + y[k];
                if(valid(row,col,n,m) && visa[row][col]==0 && a[row][col] >= a[a_r][a_c])
                {
                    visa[row][col]=1;
                    qa.push({row,col});
                }
            }
        }
        while(!qp.empty())
        {
            pair<int,int>pacific=qp.front();
            qp.pop();
            int p_r = pacific.first;
            int p_c = pacific.second;
            for(int k = 0 ; k<4 ; k++)
            {
                int row = p_r + x[k];
                int col = p_c + y[k];
                if(valid(row,col,n,m) && visp[row][col]==0 && a[row][col] >= a[p_r][p_c])
                {
                    visp[row][col]=1;
                    qp.push({row,col});
                }
            }

        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visp[i][j] && visa[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
};
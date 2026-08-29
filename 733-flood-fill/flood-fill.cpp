class Solution {
public:
    int x [4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
    bool valid (int i , int j , int n , int m )
    {
        if(i<0 || i>=n || j<0 || j>=m)
        {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>&a, int sr,int s , int oldcolor,int color)
    {
        int n = a.size();
        int m = a[0].size();
        a[sr][s]=color;
        for(int k = 0 ;k<4;k++)
        {
            int row = sr+x[k];
            int col = s+y[k];
            if(valid(row,col,n,m)&& a[row][col]==oldcolor)
            {
                dfs(a,row,col,oldcolor,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        if(oldcolor==color)
            return image;
        dfs(image,sr,sc,oldcolor,color);
        return image;
    }
};
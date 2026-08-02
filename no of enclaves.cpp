You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid,int dr[],int dc[])
    {
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
            {
                dfs(nr,nc,vis,grid,dr,dc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                dfs(0,j,vis,grid,dr,dc);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1)
            {
                dfs(n-1,j,vis,grid,dr,dc);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                dfs(i,0,vis,grid,dr,dc);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i,m-1,vis,grid,dr,dc);
            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    cnt++;

                }
            }
        }
        return cnt;
    }
};

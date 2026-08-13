class Solution {
public:
//recursion
    int path(int i,int j,vector<vector<int>> &grid)
    {
        //base case
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0 || j<0)
        {
            return 1e9;
        }
        int up=grid[i][j]+path(i-1,j,grid);
        int left=grid[i][j]+path(i,j-1,grid);
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return path(n-1,m-1,grid);
    }
//memoization
int path(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        //base case
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0 || j<0)
        {
            return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j]+path(i-1,j,grid,dp);
        int left=grid[i][j]+path(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return path(n-1,m-1,grid,dp);
    }

//tabulation
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else{
                    int up=1e9,left=1e9;// if(i<0 || j<0) we shoukd take the large number so that
                    if(i>0) up=grid[i][j]+dp[i-1][j];
                    if(j>0) left=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

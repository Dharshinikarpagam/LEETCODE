class Solution {
public:
    //recursion
    int path(int i,int j,vector<vector<int>> &obstacleGrid)
    {
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0 ) return 1;
        if(i<0 || j<0) return 0;
        int up=path(i-1,j,obstacleGrid);
        int left=path(i,j-1,obstacleGrid);
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        return path(n-1,m-1,obstacleGrid);
    }

 //memoization
    int mod=(int)1e9+7;
    int path(int i,int j,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp)
    {
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0 ) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=path(i-1,j,obstacleGrid,dp);
        int left=path(i,j-1,obstacleGrid,dp);
        return dp[i][j]=(up+left)%mod;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return path(n-1,m-1,obstacleGrid,dp);
    }
//tabulation
int mod=(int)1e9+7;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=0;
                int left=0;
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=(up+left)%mod;
                }

            }
        }
        return dp[n-1][m-1];
    }
};

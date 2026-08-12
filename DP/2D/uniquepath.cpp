class Solution {
public:
    //recursion
    int path(int i,int j)
    {
        //base case
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        int up=path(i-1,j);
        int left=path(i,j-1);
        return up+left;
    }
    int uniquePaths(int m, int n) {
       return path(m-1,n-1);   
    }

//memoization
    int path(int i,int j,vector<vector<int>> &dp)
    {
        //base case
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up=path(i-1,j,dp);
        int left=path(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return path(m-1,n-1,dp); 
    }

//tabulation
int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
         dp[0][0]=1;
         for(int i=0;i<m;i++)
         {
            int up=0;
            int left=0;
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
         }
         return dp[m-1][n-1];
    }
};

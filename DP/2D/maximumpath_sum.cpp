class Solution {
  public:
  //recursion
    int path(int i,int j, vector<vector<int>> &mat,int n,int m)
    {
        if(j<0 || j>=m) return -1e8;
        if(i==0)
        {
            return mat[0][j];
        }
        int s=mat[i][j]+path(i-1,j,mat,n,m);
        int dl=mat[i][j]+path(i-1,j-1,mat,n,m);
        int dr=mat[i][j]+path(i-1,j+1,mat,n,m);
        return max(s,max(dl,dr));
    }
    int maximumPath(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       int maxi=-1e8;
       for(int j=0;j<m;j++)
       {
           maxi=max(maxi,path(n-1,j,mat,n,m));
       }
        return maxi;
    }
//memoization
    int path(int i,int j, vector<vector<int>> &mat,int n,int m,vector<vector<int>> &dp)
    {
        if(j<0 || j>=m) return -1e8;
        if(i==0)
        {
            return mat[0][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int s=mat[i][j]+path(i-1,j,mat,n,m,dp);
        int dl=mat[i][j]+path(i-1,j-1,mat,n,m,dp);
        int dr=mat[i][j]+path(i-1,j+1,mat,n,m,dp);
        return dp[i][j]=max(s,max(dl,dr));
    }
    int maximumPath(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       int maxi=-1e8;
       vector<vector<int>> dp(n,vector<int>(m,-1));
       for(int j=0;j<m;j++)
       {
           maxi=max(maxi,path(n-1,j,mat,n,m,dp));
       }
        return maxi;
    }
//tabulation
int maximumPath(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       vector<vector<int>> dp(n,vector<int>(m,-1));
       int maxi=-1e8;
       for(int j=0;j<m;j++)
       {
           dp[0][j]=mat[0][j];
       }
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               int s=mat[i][j]+dp[i-1][j];
               int dl=mat[i][j];
               if(j-1 >=0){ 
                   dl+=dp[i-1][j-1];
               }
               else{
                   dl+=-1e8;
               }
               int dr=mat[i][j];
               if(j+1<m){
                   dr+=dp[i-1][j+1];
               }else{
                   dr+=-1e8;
               }
               dp[i][j]=max(s,max(dl,dr));
           }
       }
       for(int j=0;j<m;j++)
       {
           maxi=max(maxi,dp[n-1][j]);
       }
       
        return maxi;
    }
};

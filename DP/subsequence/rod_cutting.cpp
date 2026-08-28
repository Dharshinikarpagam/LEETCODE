//think it as the unbounded knapsack (get a rod len and sum to give the total length the  max the price)
class Solution {
  public:
  //recursion 
    int cut(int ind,int N,vector<int> &price)
    {
        if(ind==0)
        {
            return N*price[0];
        }
        int ntake=0+cut(ind-1,N,price);
        int take=INT_MIN;
        int rodlen=ind+1;
        if(rodlen<=N)
        {
            take=price[ind]+cut(ind-1,N-rodlen,price);
        }
        return max(ntake,take);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        return cut(n-1,n,price);  
    }
//memoization
 int cut(int ind,int N,vector<int> &price,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            return N*price[0];
        }
        if(dp[ind][N]!=-1) return dp[ind][N];
        int ntake=0+cut(ind-1,N,price,dp);
        int take=INT_MIN;
        int rodlen=ind+1;
        if(rodlen<=N)
        {
            take=price[ind]+cut(ind-1,N-rodlen,price,dp);
        }
        return dp[ind][N]=max(ntake,take);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return cut(n-1,n,price,dp);
    }
//tabulation
int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int N=0;N<=n;N++)
        {
            dp[0][N]=N*price[0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int ntake=0+dp[i-1][j];
                int take=INT_MIN;
                int rodlen=i+1;
                if(rodlen<=j)
                {
                    take=price[i]+dp[i][j-rodlen];
                }
                dp[i][j]=max(ntake,take);
            }
        }
        return dp[n-1][n];
    }
};

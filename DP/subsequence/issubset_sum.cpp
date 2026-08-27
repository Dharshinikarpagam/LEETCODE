class Solution {
  public:
    //recursion
    bool subsum(int ind,vector<int> &arr,int t)
    {
        if(t==0) return true;
        if(ind==0) return arr[0]==t;
        bool ntake=subsum(ind-1,arr,t);
        bool take=false;
        if(arr[ind]<=t) take=subsum(ind-1,arr,t-arr[ind]);
        return ntake||take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
       int n=arr.size();
       return subsum(n-1,arr,sum);
    }

//memoization
    bool subsum(int ind,vector<int> &arr,int t,vector<vector<int>> &dp)
    {
        if(t==0) return true;
        if(ind==0) return arr[0]==t;
        if(dp[ind][t]!=-1) return dp[ind][t];
        bool ntake=subsum(ind-1,arr,t,dp);
        bool take=false;
        if(arr[ind]<=t) take=subsum(ind-1,arr,t-arr[ind],dp);
        return dp[ind][t]=ntake||take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
       int n=arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,-1));
       return subsum(n-1,arr,sum,dp);
    }

//tabulation
bool isSubsetSum(vector<int>& arr, int sum) {
       int n=arr.size();
       vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
       for(int i=0;i<n;i++)
       {
           dp[i][0]=true;
       }
       if(arr[0]<=sum)
       {
           dp[0][arr[0]]=sum;
       }
       for(int i=1;i<n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               bool ntake=dp[i-1][j];
               bool take=false;
               if(arr[i]<=j)
               {
                   take=dp[i-1][j-arr[i]];
               }
               dp[i][j]=take||ntake;
           }
       }
       return dp[n-1][sum];
    }

};

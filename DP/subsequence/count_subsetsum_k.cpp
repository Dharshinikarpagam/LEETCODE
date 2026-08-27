class Solution {
//recursion
  public:
    int mod=1e9+7;
    int solve(int ind,int tar,vector<int> &arr)
    {
        if(tar==0) return 1;
        if(ind==0){
           // Two subsets: {} and {0}
            if(tar==0 && arr[0]==0)
                return 2;
           // Empty subset || //first element
            if(arr[ind]==tar|| tar==0)
                return 1;
            else
                return 0;
        }
        int ntake=solve(ind-1,tar,arr);
        int take=0;
        if(arr[ind]<=tar)
        {
            take=solve(ind-1,tar-arr[ind],arr);
        }
        return (take+ntake)%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
       int n=arr.size();
       return solve(n-1,target,arr);
        
    }
//memoization
 int mod=1e9+7;
    int solve(int ind,int tar,vector<int> &arr,vector<vector<int>> &dp)
    {
        if(ind==0){
            if(tar==0 && arr[0]==0){
                return 2;
            }
            if(arr[0]==tar || tar==0)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int ntake=solve(ind-1,tar,arr,dp);
        int take=0;
        if(arr[ind]<=tar)
        {
            take=solve(ind-1,tar-arr[ind],arr,dp);
        }
        return dp[ind][tar]=(take+ntake)%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
       int n=arr.size();
       vector<vector<int>> dp(n,vector<int>(target+1,-1));
       return solve(n-1,target,arr,dp);
        
    }
//tabulation
int perfectSum(vector<int>& arr, int target) {
       int n=arr.size();
       vector<vector<int>> dp(n,vector<int>(target+1,0));
       // If first element is 0:
       // {} and {0} both have sum = 0, so there are 2 subsets.
       if(arr[0]==0) 
           dp[0][0]=2;
       else
            dp[0][0]=1;
       if(arr[0]!=0 && arr[0]<=target)
       {
           dp[0][arr[0]]=1;
       }
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<=target;j++)
           {
               int ntake=dp[i-1][j];
               int take=0;
               if(arr[i]<=j){ 
                   take=dp[i-1][j-arr[i]];
               }
               dp[i][j]=(take+ntake)%mod;
           }
       }
       return dp[n-1][target];
        
    }
};

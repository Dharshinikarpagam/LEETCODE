//same as count no of subsets whose sum=k with partition s1 ans s2 and s1>=s2 where |s1-s2|=diff 
//s1=totalsum-s2 -> totalsum-s2-s2=d ->> (totalsum-d)/2=s2 
//where count the no of subsets where target is (totalsum-d)/2 and the contraints are (totalsum-d)<0 || (totalsum-d)%2==1 return false
//tabulation
class Solution {
  public:
    int mod=1e9+7;
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
    int countPartitions(vector<int>& arr, int diff) {
       int n=arr.size();
       int tot=0;
       for(auto &it:arr)
       {
           tot+=it;
       }
       if((tot-diff)<0 || (tot-diff)%2==1) return false;
       return perfectSum(arr,(tot-diff)/2);
        
    }
};

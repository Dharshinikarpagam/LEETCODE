//same as the count partition here the question has given that assign + and -ve sign to the numbers such that it is equal to target
class Solution {
public:
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
               dp[i][j]=(take+ntake);
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
       if((tot-diff)<0 || (tot-diff)%2==1) return 0;
       return perfectSum(arr,(tot-diff)/2);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};

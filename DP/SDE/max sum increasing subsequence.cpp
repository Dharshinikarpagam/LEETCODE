class Solution {
  public:
  //recursion
    int maxs(int ind,int pre,vector<int> &arr,int n)
    {
        if(ind==n)
        {
            return 0;
        }
        int ntake=maxs(ind+1,pre,arr,n);
        int take=INT_MIN;
        if(pre==-1|| arr[ind]>arr[pre])
        {
            take=arr[ind]+maxs(ind+1,ind,arr,n);
        }
        return max(ntake,take);
    }
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        return maxs(0,-1,arr,n);
        
    }

//memoization
    int maxs(int ind,int pre,vector<int> &arr,int n,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][pre+1]!=-1) return dp[ind][pre+1];
        int ntake=maxs(ind+1,pre,arr,n,dp);
        int take=INT_MIN;
        if(pre==-1|| arr[ind]>arr[pre])
        {
            take=arr[ind]+maxs(ind+1,ind,arr,n,dp);
        }
        return dp[ind][pre+1]=max(ntake,take);
    }
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return maxs(0,-1,arr,n,dp);
        
    }
//tabulation
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        vector<int> dp(n,0);
        for(int i = 0; i < n; i++) // each element is itself a increasing subsequence
        {
            dp[i] = arr[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int p=0;p<i;p++)
            {
                if(arr[i]>arr[p])
                {
                    dp[i]=max(dp[i],arr[i]+dp[p]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }


};

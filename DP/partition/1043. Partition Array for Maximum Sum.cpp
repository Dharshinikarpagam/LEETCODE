class Solution {
public:
//recursion
    int func(int ind,int n,int k,vector<int> &arr)
    {
        if(ind==n) return 0;
        int len=0;
        int maxi=INT_MIN;
        int maxans=INT_MIN;
        for(int j=ind;j<min(ind+k,n);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+func(j+1,n,k,arr);
            maxans=max(maxans,sum);
        }
        return maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        return func(0,n,k,arr);
    }
//memoization
    int func(int ind,int n,int k,vector<int> &arr,vector<int> &dp)
    {
        if(ind==n) return 0;
        int len=0;
        int maxi=INT_MIN;
        int maxans=INT_MIN;
        if(dp[ind]!=-1) return dp[ind];
        for(int j=ind;j<min(ind+k,n);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+func(j+1,n,k,arr,dp);
            maxans=max(maxans,sum);
        }
        return dp[ind]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return func(0,n,k,arr,dp);
    }
//tabulation

int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            int len=0;
            int maxi=INT_MIN;
            int maxans=INT_MIN;
            for(int j=ind;j<min(ind+k,n);j++)
            {
                len++;
                maxi=max(maxi,arr[j]);
                int sum=(len*maxi)+dp[j+1];
                maxans=max(maxans,sum);
            }
            dp[ind]=maxans;
        }
        return dp[0];
    }
};

class Solution {
public:
    //recursion
    int nopolice(vector<int> &nums,int n)
    {
        if(n<0) return 0;
        if(n==0) return nums[0];
        int rob=nums[n]+nopolice(nums,n-2);
        int norob=nopolice(nums,n-1);
        return max(rob,norob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return nopolice(nums,n-1);
    }
//memoization
int nopolice(vector<int> &nums,int n,vector<int> &dp)
    {
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int rob=nums[n]+nopolice(nums,n-2,dp);
        int norob=nopolice(nums,n-1,dp);
        return dp[n]=max(rob,norob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return nopolice(nums,n-1,dp);
    }
//tabulation
int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int robb=(i>1)? nums[i]+dp[i-2]:nums[i];
            int norob=dp[i-1];
            dp[i]=max(robb,norob);
        }
        return dp[n-1];
    }
};

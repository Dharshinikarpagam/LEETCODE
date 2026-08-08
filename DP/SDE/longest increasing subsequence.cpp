class Solution {
public:
    // recursion
    int func(int ind,int pre,vector<int> &nums,int n)
    {
        if(ind==n)
        {
            return 0;
        }
        int len=0+func(ind+1,pre,nums,n);
        if(pre==-1 || nums[ind]>nums[pre])
        {
            len=max(len,1+func(ind+1,ind,nums,n));
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return func(0,-1,nums,n);
    }

// memoization
int func(int ind,int pre,vector<int> &nums,int n,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][pre+1]!=0) return dp[ind][pre+1];
        int len=0+func(ind+1,pre,nums,n,dp);
        if(pre==-1 || nums[ind]>nums[pre])
        {
            len=max(len,1+func(ind+1,ind,nums,n,dp));
        }
        return dp[ind][pre+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        return func(0,-1,nums,n,dp);
    }

// tabulation(1)
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int p=0;p<i;p++)
            {
                if(nums[p]<nums[i])
                {
                    dp[i]=max(dp[i],1+dp[p]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
 t       return maxi;
};

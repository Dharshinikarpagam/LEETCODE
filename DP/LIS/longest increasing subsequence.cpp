class Solution {
public:
    // recursion
    int func(int ind,int pre,vector<int> &nums,int n)
    {
        if(ind==n)
        {
            return 0;
        }
        int ntake=0+func(ind+1,pre,nums,n);
        int take=0;
        if(pre==-1 || nums[ind]>nums[pre])
        {
            take=max(take,1+func(ind+1,ind,nums,n));
        }
        return max(ntake,take);
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
        int ntake=0+func(ind+1,pre,nums,n);
        int take=0;
        if(pre==-1 || nums[ind]>nums[pre])
        {
            take=max(take,1+func(ind+1,ind,nums,n));
        }
        return dp[ind][pre]=max(ntake,take);
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

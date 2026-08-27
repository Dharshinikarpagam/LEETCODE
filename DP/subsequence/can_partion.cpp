class Solution {
public:
    //recursion
    bool solve(int ind,int t,vector<int> &nums)
    {
        if(t==0) return true;
        if(ind==0) return nums[ind]==t;
        bool ntake=solve(ind-1,t,nums);
        bool take=false;
        if(nums[ind]<=t) take=solve(ind-1,t-nums[ind],nums);
        return ntake||take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target=sum/2;
        return solve(n-1,target,nums);
    }
//memoization
    bool solve(int ind,int t,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(t==0) return true;
        if(ind==0) return nums[ind]==t;
        if(dp[ind][t]!=-1) return dp[ind][t];
        bool ntake=solve(ind-1,t,nums,dp);
        bool take=false;
        if(nums[ind]<=t) take=solve(ind-1,t-nums[ind],nums,dp);
        return dp[ind][t]=ntake||take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
//tabulation
bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        else{
            int target=sum/2;
            vector<vector<bool>> dp(n,vector<bool>(target+1,false));
            for(int i=0;i<n;i++)
            {
                dp[i][0]=true;
            }
            if(nums[0]<=target)
            {
                dp[0][nums[0]]=true;
            }
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<=target;j++)
                {
                    bool ntake=dp[i-1][j];
                    bool take=false;
                    if(nums[i]<=j) 
                    {
                        take=dp[i-1][j-nums[i]];
                    }
                    dp[i][j]=ntake||take;
                }
            }
            return dp[n-1][target];
        }
    }

};

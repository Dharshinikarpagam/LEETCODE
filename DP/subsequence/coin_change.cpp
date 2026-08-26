class Solution {
public:
    //recursion
    int solve(int ind,vector<int> &coin,int t)
    {
        if(ind==0)
        {
            if(t%coin[0]==0) return t/coin[0];
            else{
                return 1e9;
            }
        }
        int ntake=0+solve(ind-1,coin,t);
        int take=1e9;
        if(coin[ind]<=t) take=1+solve(ind,coin,t-coin[ind]);
        return min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=solve(n-1,coins,amount);
        if(ans>=1e9) return -1;
        return ans;
    }
//memoization
int solve(int ind,vector<int> &coin,int t,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(t%coin[0]==0) return t/coin[0];
            else{
                return 1e9;
            }
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
        int ntake=0+solve(ind-1,coin,t,dp);
        int take=1e9;
        if(coin[ind]<=t) take=1+solve(ind,coin,t-coin[ind],dp);
        return dp[ind][t]=min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
//tabulation
int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)
            {
                dp[0][t]=t/coins[0];
            }
            else{
                dp[0][t]=1e9;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int ntake=0+dp[i-1][t];
                int take=1e9;
                if(coins[i]<=t)
                {
                    take=1+dp[i][t-coins[i]];
                }
                dp[i][t]=min(ntake,take);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};

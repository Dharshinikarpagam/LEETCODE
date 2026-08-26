class Solution {
public:
//recursion
    int solve(int ind,vector<int> &coins,int t)
    {
        if(ind==0)
        {
            return (t%coins[0]==0);
        }
        int ntake=solve(ind-1,coins,t);
        int take=0;
        if(coins[ind]<=t)
        {
            take=solve(ind,coins,t-coins[ind]);
        }
        return ntake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return solve(n-1,coins,amount);
    }

//memoization
int solve(int ind,vector<int> &coins,int t,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            return (t%coins[0]==0);
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
        int ntake=solve(ind-1,coins,t,dp);
        int take=0;
        if(coins[ind]<=t)
        {
            take=solve(ind,coins,t-coins[ind],dp);
        }
        return dp[ind][t]=ntake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }

//tabulation
 int change(int amount, vector<int>& coins) {
        int n=coins.size();
        const long long limit=INT_MAX;
        vector<vector<long long >> dp(n,vector<long long>(amount+1,-1));
       // Amount 0 -> one combination: choose nothing
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
       //with coins[0]
        for(int t=0;t<=amount;t++)
        {
            dp[0][t]=(t%coins[0]==0);
        }
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                long long  ntake=dp[i-1][t];
                long long  take=0;
                if(coins[i]<=t){
                        take=dp[i][t-coins[i]];
                }
              //to prevent overflow
                if(take>limit-ntake)
                {
                    dp[i][t]=limit;
                }
                else{
                    dp[i][t]=ntake+take;
                }
            }
        }
        return (int)dp[n-1][amount];
    }
};

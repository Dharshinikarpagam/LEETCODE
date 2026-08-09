class Solution {
  public:
  //recursion
    int sol(int ind,vector<int> &val,vector<int> &wt,int W)
    {
        if(ind==0)
        {
            if(wt[0]<=W)
            {
                return val[0];
            }
            else{
                return 0;
            }
        }
        int ntake=0+sol(ind-1,val,wt,W);
        int take=INT_MIN;
        if(wt[ind]<=W)
        {
            take=val[ind]+sol(ind-1,val,wt,W-wt[ind]);
        }
        return max(ntake,take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        return sol(n-1,val,wt,W);
        
    }

//memoization
int sol(int ind,vector<int> &val,vector<int> &wt,int W,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(wt[0]<=W)
            {
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int ntake=0+sol(ind-1,val,wt,W,dp);
        int take=INT_MIN;
        if(wt[ind]<=W)
        {
            take=val[ind]+sol(ind-1,val,wt,W-wt[ind],dp);
        }
        return dp[ind][W]=max(ntake,take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return sol(n-1,val,wt,W,dp);
        
    }

//tabulation
 int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<=W;i++)
        {
            dp[0][i]=val[0];
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int w=0;w<=W;w++)
            {
                int ntake=0+dp[ind-1][w];
                int take=0;
                if(wt[ind]<=w)
                {
                    take=val[ind]+dp[ind-1][w-wt[ind]];
                }
                dp[ind][w]=max(ntake,take);
            }
        }
        return dp[n-1][W];
        
    }

};





//recursion
class Solution {
public:
int tribonacci(int n)
{
        if(n==0) return 0;
        if(n==1|| n==2) return 1;
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
  }

//memoization
int solve(int n,vector<int> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1 || n==2)
        {
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        int a=solve(n-1,dp);
        int b=solve(n-2,dp);
        int c=solve(n-3,dp);
        return dp[n]=a+b+c;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
//tabulation
int tribonacci(int n) {
        if(n==0)
        {
            return 0;
        }
        if(n==1 ||n==2) return 1;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};

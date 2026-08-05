class Solution {
public:
//recursion
    int climbStairs(int n) {
        if(n<=1) return 1;
        int ones=climbStairs(n-1);
        int twos=climbStairs(n-2);
        return ones+twos;
    }
//memoization
    int stair(int n,vector<int> &dp)
    {
        if(n<=1) return 1 ;
        if(dp[n]!=-1) return dp[n];
        int ones=stair(n-1,dp);
        int twos=stair(n-2,dp);
        return dp[n]=ones+twos;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return stair(n,dp);
    }
//tabulation
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        if(n<0) return 0;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

};

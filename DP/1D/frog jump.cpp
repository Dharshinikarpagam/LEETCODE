class Solution {
  public:
    //recursion
    int jump(int i,int n,vector<int> &height)
    {
        if(i==n-1) return 0;
        int ones=abs(height[i]-height[i+1])+jump(i+1,n,height);
        int twos=INT_MAX;
        if(i+2<n)
        {
            twos=abs(height[i]-height[i+2])+jump(i+2,n,height);
        }
        return min(ones,twos);
        
    }
    int minCost(vector<int>& height) {
        int n=height.size();
        return jump(0,n,height);
        
    }
//memoization
int jump(int i,int n,vector<int> &height,vector<int> &dp)
    {
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ones=abs(height[i]-height[i+1])+jump(i+1,n,height,dp);
        int twos=INT_MAX;
        if(i+2<n)
        {
            twos=abs(height[i]-height[i+2])+jump(i+2,n,height,dp);
        }
        return dp[i]=min(ones,twos);
        
    }
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,-1);
        return jump(0,n,height,dp);    
    }
//tabulation
int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,-1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int ones;
            ones=abs(height[i]-height[i+1])+dp[i+1];
            int twos=INT_MAX;
            if(i+2<n)
                twos=abs(height[i]-height[i+2])+dp[i+2];
            dp[i]=min(ones,twos);
        }
        return dp[0];
    }
};

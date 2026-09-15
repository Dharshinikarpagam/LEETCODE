class Solution {
public:
//recursion
 bool ispalindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int fuc(int i,int n,string &s)
    {
        int mincost=INT_MAX;
        if(i==n) return 0;
        for(int j=i;j<n;j++)
        {
            if(ispalindrome(i,j,s))
            {
                int cost=1+fuc(j+1,n,s);
                mincost=min(mincost,cost);
            }
        }
        return mincost;
    }
    int mincut(string &s) {
        int n=s.size();
        return fuc(0,n,s)-1;
        
    }

//memoization
bool ispalindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int fuc(int i,int n,string &s,vector<int> &dp)
    {
        int mincost=INT_MAX;
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n;j++)
        {
            if(ispalindrome(i,j,s))
            {
                int cost=1+fuc(j+1,n,s,dp);
                mincost=min(mincost,cost);
            }
        }
        return dp[i]=mincost;
    }
    int mincut(string &s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return fuc(0,n,s,dp)-1;
        
    }
//tabulation 
    bool ispalindrome(int i,int j,string s)
    {
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int mincost=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(ispalindrome(i,j,s))
                {
                    int cost=1+dp[j+1];
                    mincost=min(mincost,cost);
                }
            }
            dp[i]=mincost;
        }
        return dp[0]-1;
    }
};

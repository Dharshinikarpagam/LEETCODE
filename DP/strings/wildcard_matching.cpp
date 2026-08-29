class Solution {
public:
//recursion
    bool match(int ind1,int ind2,string &s,string &p)
    {
        if(ind1<0 && ind2<0) return true;
        if(ind2<0 && ind1>=0) return false;
        if(ind1<0 && ind2>=0)
        {
            for(int i=0;i<=ind2;i++)
            {
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(s[ind1]==p[ind2] || p[ind2]=='?') {
            return match(ind1-1,ind2-1,s,p);
        }
        if(p[ind2]=='*')
        {
            return match(ind1-1,ind2,s,p)|| match(ind1,ind2-1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return match(n-1,m-1,s,p);
    }
//memoization
bool match(int ind1,int ind2,string &s,string &p,vector<vector<int>> &dp)
    {
        if(ind1==0 && ind2==0) return true;
        if(ind2==0 && ind1>0) return false;
        if(ind1==0 && ind2>0)
        {
            for(int i=1;i<=ind2;i++)
            {
                if(p[i-1]!='*') return false;
            }
            return true;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1-1]==p[ind2-1] || p[ind2-1]=='?') {
            return dp[ind1][ind2]=match(ind1-1,ind2-1,s,p,dp);
        }
        if(p[ind2-1]=='*')
        {
            return dp[ind1][ind2]=match(ind1-1,ind2,s,p,dp)|| match(ind1,ind2-1,s,p,dp);
        }
        return dp[ind1][ind2]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return match(n,m,s,p,dp);
    }
//tabulation
bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=false;
        }
        for(int j=0;j<=m;j++)
        {   
            bool flag=true;
            for(int i=1;i<=j;i++)
            {
                if(p[i-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};

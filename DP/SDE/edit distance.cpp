class Solution {
public:
//recursion
    int match(int i,int j,string &s1,string &s2)
    {
        //base case
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i]==s2[j])
        {
            return match(i-1,j-1,s1,s2);
        }
        return 1+min(match(i,j-1,s1,s2),min(match(i-1,j,s1,s2),match(i-1,j-1,s1,s2)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return match(n-1,m-1,word1,word2);
    }

//memoization
    int match(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        //base case
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
        {
            return match(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=1+min(match(i,j-1,s1,s2,dp),min(match(i-1,j,s1,s2,dp),match(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return match(n-1,m-1,word1,word2,dp);
    }

int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base case 
        for(int i=0;i<=n;i++)  //s2 is exhausted 
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++)  // s1 is exhausted
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1]) // here dp[i][j]= first i characters of word1 and the first j characters of word2.
                {
                     dp[i][j]=dp[i-1][j-1];
                }
                else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};

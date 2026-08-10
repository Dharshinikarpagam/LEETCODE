class Solution {
  public:
    //recursion
    int merit(int day,int last,vector<vector<int>> &mat)
    {
        if(day==0)
        {
            int maxi=0;
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    maxi=max(maxi,mat[0][i]);
                }
            }
            return maxi;
        }
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                int points=mat[day][i]+merit(day-1,i,mat);
                maxi=max(maxi,points);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
        return merit(n-1,3,mat);
        
    }

 //memoization
    int merit(int day,int last,vector<vector<int>> &mat,vector<vector<int>> &dp)
    {
        if(day==0)
        {
            int maxi=0;
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    maxi=max(maxi,mat[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                int points=mat[day][i]+merit(day-1,i,mat,dp);
                maxi=max(maxi,points);
            }
        }
        return dp[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return merit(n-1,3,mat,dp);
    }

//tabulation
int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        dp[0][0]=max(mat[0][1],mat[0][2]);
        dp[0][1]=max(mat[0][0],mat[0][2]);
        dp[0][2]=max(mat[0][0],mat[0][1]);
        dp[0][3]=max(mat[0][0],max(mat[0][1],mat[0][2]));
        for(int day=1;day<n;day++)
        {
            for(int last=0;last<4;last++)
            {
                dp[day][last]=0;
                for(int i=0;i<3;i++)
                {
                    if(i!=last)
                    {
                        int points=mat[day][i]+dp[day-1][i];
                        dp[day][last]=max(dp[day][last],points);
                    }
                }
            }
        }
        return dp[n-1][3];
        
    }
};

class Solution {
  public:
    int minDifference(vector<int>& arr) {
                int n=arr.size();
                int tot=0;
                for(int i=0;i<n;i++)
                {
                    tot+=arr[i];
                }
                int k=tot;
                vector<vector<bool>> dp(n,vector<bool>(k+1,false));
                for(int i=0;i<n;i++)
                {
                    dp[i][0]=true;
                }
                if(arr[0]<=k)
                {
                    dp[0][arr[0]]=true;
                }
                for(int i=1;i<n;i++)
                {
                    for(int j=1;j<=k;j++)
                    {
                        bool ntake=dp[i-1][j];
                        bool take=false;
                        if(arr[i]<=j)
                        {
                            take=dp[i-1][j-arr[i]];
                        }
                        dp[i][j]=ntake||take;
                    }
                }
                int mini=1e9;
                for(int i=0;i<=tot/2;i++)
                {
                    if(dp[n-1][i]==true)
                    {
                        mini=min(mini,abs((tot-i)-i));
                    }
                }
     return mini;
        
    }
};

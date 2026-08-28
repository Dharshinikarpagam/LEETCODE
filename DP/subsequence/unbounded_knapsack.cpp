//same as 0/1 knapsack but here there is infinite supplies of wts 
class Solution {
  public:
  //recursion 
    int sack(int ind,int w,vector<int> &val,vector<int> &wt){
        if(ind==0)
        {
            return ((int)w/wt[0])*val[0];
        }
        int ntake=0+sack(ind-1,w,val,wt);
        int take=INT_MIN;
        if(wt[ind]<=w)
        {
            take=val[ind]+sack(ind,w-wt[ind],val,wt);
        }
        return max(ntake,take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       int n=wt.size();
       return sack(n-1,capacity,val,wt);   
    }
//memoization
 int sack(int ind,int w,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp){
        if(ind==0)
        {
            return ((int)w/wt[0])*val[0];
        }
        if(dp[ind][w]!=-1) return dp[ind][w];
        int ntake=0+sack(ind-1,w,val,wt,dp);
        int take=INT_MIN;
        if(wt[ind]<=w)
        {
            take=val[ind]+sack(ind,w-wt[ind],val,wt,dp);
        }
        return dp[ind][w]=max(ntake,take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       int n=wt.size();
       vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
       return sack(n-1,capacity,val,wt,dp); 
    }
//tabulation
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       int n=wt.size();
       vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
       for(int w=0;w<=capacity;w++)
       {
           dp[0][w]=((int)w/wt[0])*val[0];
       }
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<=capacity;j++)
           {
               int ntake=0+dp[i-1][j];
               int take=INT_MIN;
               if(wt[i]<=j)
               {
                   take=val[i]+dp[i][j-wt[i]];
               }
               dp[i][j]=max(ntake,take);
           }
       }
       return dp[n-1][capacity];
    }
};

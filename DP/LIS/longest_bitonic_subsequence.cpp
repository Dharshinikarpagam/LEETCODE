class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
            vector<int> dp1(n,1);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(nums[i]>nums[j] && 1+dp1[j]>dp1[i])
                    {
                        dp1[i]=1+dp1[j];
                    }
                }
            }
            vector<int> dp2(n,1);
            for(int i=n-1;i>=0;i--)
            {
                for(int j=n-1;j>i;j--)
                {
                    if(nums[i]>nums[j] && 1+dp2[j]>dp2[i])
                    {
                        dp2[i]=1+dp2[j];
                    }
                }
            }
            int maxi=0;
            for(int i=0;i<n;i++)
            {
                 if(dp1[i]>1 && dp2[i]>1){ // to ensure that we dont consider lis or lds as LBS("The current element must have an increasing part BEFORE it and a decreasing part AFTER it.")
                  maxi=max(maxi,dp1[i]+dp2[i]-1);
                 }
            }
            return maxi;
        
    }
};

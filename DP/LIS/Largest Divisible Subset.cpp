class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=1;
        int lastin=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastin=i;
            }
        }
        vector<int> lds;
        while(hash[lastin]!=lastin)
        {
            lds.push_back(nums[lastin]);
            lastin=hash[lastin];
        }
        lds.push_back(nums[lastin]);
        reverse(lds.begin(),lds.end());
        return lds;
    }
};

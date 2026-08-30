class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=1;
        int lastin=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int pre=0;pre<i;pre++)
            {
                if(arr[pre]<arr[i] && 1+dp[pre]>dp[i])
                {
                    dp[i]=1+dp[pre];
                    hash[i]=pre;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastin=i;
            }
        }
        vector<int> lis;
        while(hash[lastin]!=lastin){
            lis.push_back(arr[lastin]);
            lastin=hash[lastin];
        }
        lis.push_back(arr[lastin]);
        reverse(lis.begin(),lis.end());
        return lis;
    }
};

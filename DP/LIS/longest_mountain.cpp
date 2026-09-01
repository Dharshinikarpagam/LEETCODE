// Same concept as LBS (Longest Bitonic Subsequence),
// but here we consider only consecutive elements.

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp1(n,1);
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                dp1[i]=1+dp1[i-1];
            }
        }
        vector<int> dp2(n,1);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                dp2[i]=1+dp2[i+1];
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(dp1[i]>1 && dp2[i]>1){
             maxi=max(maxi,dp1[i]+dp2[i]-1);
            }
        }
        return maxi;
    }
};

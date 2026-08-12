class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans;
        long long  n=arr.size();
        long long s1=1LL*n*(n+1)/2;
        long long s2=1LL*n*(n+1)*(2*n+1)/6;
        long long s=0;
        long long sm=0;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            sm+=1LL*arr[i]*arr[i];
        }
        long long val1=s-s1;
        long long val2=sm-s2;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        ans.push_back(int(x));
        ans.push_back(int(y));
        return ans;
        
    }
};

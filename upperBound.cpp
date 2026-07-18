class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int ans=n;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]>target)
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};

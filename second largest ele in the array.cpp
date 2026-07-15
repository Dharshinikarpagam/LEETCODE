class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
        int l=INT_MIN;
        int sl=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>l)
            {
                sl=l;
                l=arr[i];
            }
            else if(arr[i]>sl && arr[i]!=l)
            {
                sl=arr[i];
            }
        }
        if(sl==INT_MIN) return -1;
        return sl;
        
    }
};

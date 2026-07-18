class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
       int n=arr.size();
       d=d%n;
       vector<int> temp(n);
       for(int i=0;i<n-d;i++)
       {
           temp[i]=arr[d+i];
       }
       for(int i=0;i<d;i++)
       {
           temp[n-d+i]=arr[i];
       }
       for(int i=0;i<n;i++)
       {
           arr[i]=temp[i];
       }
        
    }
};

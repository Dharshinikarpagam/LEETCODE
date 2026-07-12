1) soln

class Solution {
  public:
    void func(int l,int r,vector<int>& arr)
    {
        if(l>=r)
        {
            return;
        }
        int temp=arr[r];
        arr[r]=arr[l];
        arr[l]=temp;
        func(l+1,r-1,arr);
    }
    void reverseArray(vector<int> &arr) {
        int n=arr.size();
        func(0,n-1,arr);
        
    }
};

2) soln

void func(int i,int n,vector<int>& arr)
    {
        if(i>=n/2)
        {
            return ;
        }
        int temp=arr[n-i-1];
        arr[n-i-1]=arr[i];
        arr[i]=temp;
        func(i+1,n,arr);
    }
    void reverseArray(vector<int> &arr) {
        int n=arr.size();
        func(0,n,arr);
        
    }

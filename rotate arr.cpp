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

2)right rotate by k steps
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
       /* vector<int> temp(n);
        //right rotate copy last element first 
        for(int i=0;i<k;i++)
        {
            temp[i]=nums[n-k+i];
        }
        for(int i=0;i<n-k;i++)
        {
            temp[k+i]=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=temp[i];
        }*/
        reverse(nums.begin(),nums.begin()+(n-k));
        reverse(nums.begin()+(n-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};

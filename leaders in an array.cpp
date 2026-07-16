class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
       int n=arr.size();
       vector<int> ans;
       int max=arr[n-1];
       ans.push_back(arr[n-1]);
       for(int i=n-2;i>=0;i--)
       {
           if(arr[i]>=max)
           {
               ans.push_back(arr[i]);
               max=arr[i];
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
        
    }
};

Time Complexity: O(N), where N is the size of the input array. This is because we traverse the array only once.

Space Complexity: O(1), as we are using only a constant amount of extra space.

class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        vector<vector<int>> ans;
        for(auto it:mpp){
            ans.push_back({it.first,it.second});
        }
        return ans;
        
    }
};

class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        int maxfreq=0;
        int maxele=INT_MAX;
        for(auto it:mpp)
        {
            int ele=it.first;
            int cnt=it.second;
            if(cnt>maxfreq)
            {
                maxele=ele;
                maxfreq=cnt;
            }
            // if two number has the same freq need to take the greater ele
            else if(cnt==maxfreq && ele>maxele)
            {
                maxele=ele;
            }
        }
        return maxele;
        
    }
};

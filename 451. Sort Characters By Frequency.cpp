class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        vector<pair<char,int>> fre;
        for(char ch:s)
        {
            mp[ch]++;
        }
        for(auto it:mp)
        {
            fre.push_back({it.first,it.second});
        }
        sort(fre.begin(),fre.end(),[](pair<char,int> a,pair<char,int> b){
             return a.second>b.second;
        });
        string ans="";
        for(auto it:fre)
        {
            ans+=string(it.second,it.first);

        }
        return ans;
        
    }
};

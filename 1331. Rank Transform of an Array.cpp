class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        int rank=1;
        unordered_map<int,int> map;
        vector<int> sa=arr;
        sort(sa.begin(),sa.end());
        for(int num: sa)
        {
            if(map.find(num)==map.end())
            {
                map[num]=rank;
                rank++;
            }
        }
        vector<int> res;
        for(int num:arr)
        {
            res.push_back(map[num]);
        }
        return res;
    }
};

Time Complexity: O(N log N), We sort the array which takes O(N log N), then loop over the array multiple times all O(N) operations.

Space Complexity: O(N), We store an extra hash map for ranks and copy of the array.

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a(nums1.begin(),nums1.end());
        unordered_set<int> b(nums2.begin(),nums2.end());
        vector<int> ans1,ans2;
        for(int num:a)
        {
            if(b.count(num)==0)
            {
                ans1.push_back(num);
            }
        }
        for(int num:b)
        {
            if(a.count(num)==0)
            {
                ans2.push_back(num);
            }
        }
        return {ans1,ans2};

    }
};

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array 
such that nums[i] == nums[j] and abs(i - j) <= k.


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(nums[i])!=mpp.end())
            {
                if(abs(i-mpp[nums[i]])<=k)
                {
                    return true;
                }
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};

class Solution {
public:
    int subarr(vector<int>& nums, int k)
    {
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        map<int,int> mpp;
        while(r<n)
        {
            mpp[nums[r]]++;
            while(mpp.size()>k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size()<=k)
            {
                cnt=cnt+(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarr(nums,k)-subarr(nums,k-1);
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fir=-1;
        int end=-1;
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                fir=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        low=0;
        high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                end=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {fir,end};
    }
};

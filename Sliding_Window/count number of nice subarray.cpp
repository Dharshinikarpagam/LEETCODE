class Solution {
public:
    int sub(vector<int>& nums,int goal)
    {
        int n=nums.size();
        if(goal<0) return 0;
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        while(r<n)
        {
            sum=sum+(nums[r]%2);
            while(sum>goal)
            {
                sum=sum-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sub(nums,k)-sub(nums,k-1);
    }
};

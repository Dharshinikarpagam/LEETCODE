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
            sum=sum+nums[r];
            while(sum>goal)
            {
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
            return sub(nums,goal)-sub(nums,goal-1);   
    }
};

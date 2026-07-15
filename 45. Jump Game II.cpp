You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.


  class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int jump=0;
        if(n==1) return 0;
        while(r<n-1)
        {
            int far=0;
            for(int i=l;i<=r;i++)
            {
                far=max(far,i+nums[i]);
            }
            l=r+1;
            r=far;
            jump+=1;
        }
        return jump;
        
    }
};
#TC :O(N)
#SC:O(1)

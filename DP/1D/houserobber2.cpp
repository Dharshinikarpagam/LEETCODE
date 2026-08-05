class Solution {
public:
 int nopolice(vector<int> &nums)
 {   
    int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int robb=(i>1)? nums[i]+dp[i-2]:nums[i];
            int norob=dp[i-1];
            dp[i]=max(robb,norob);
        }
        return dp[n-1];
 }
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int> house1(nums.begin(),nums.end()-1);//house 0 to n-2;
    vector<int> housel(nums.begin()+1,nums.end());// house 1 to n-1;
    return max(nopolice(house1),nopolice(housel));    
}
};

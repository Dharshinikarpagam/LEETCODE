class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            int sum=0;
            while(ele>0)
            {
                sum+=ele%10;
                ele=ele/10;
            }
            if(sum==i)
            {
                return i;
            }
        }
        return -1;
    }
};

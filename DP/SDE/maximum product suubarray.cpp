class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        int mp=nums[0];
        int mip=nums[0];
        for(int i=1;i<n;i++)
        {
            int c=nums[i];
            if(c<0)
            {
                swap(mp,mip);
            }
            mp=max(c,mp*c);
            mip=min(c,mip*c);
            res=max(res,mp);
        }
        return res;
    }
};

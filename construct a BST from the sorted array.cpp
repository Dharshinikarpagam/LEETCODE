class Solution {
public:
    TreeNode* create(vector<int>& nums,int l,int h)
    {
        if(l>h)
        {
            return NULL;
        }
        int mid=(l+h)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=create(nums,l,mid-1);
        root->right=create(nums,mid+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            int n=nums.size();
            return create(nums,0,n-1);    
    }
};

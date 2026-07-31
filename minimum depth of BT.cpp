class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=minDepth(root->left);
        int rh=minDepth(root->right);
        if(root->left==NULL)
        {
            return 1+rh;
        }
        if(root->right==NULL)
        {
            return 1+lh;
        }

        return 1+min(lh,rh);
    }
};

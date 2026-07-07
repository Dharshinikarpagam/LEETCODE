class Solution {
public:
    bool issym(TreeNode* left,TreeNode* right)
    {
        if(left==NULL || right==NULL)
        {
            return left==right;
        }
        if(left->val!=right->val) return false;
        return issym(left->left,right->right)&& issym(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || issym(root->left,root->right);
    }
};

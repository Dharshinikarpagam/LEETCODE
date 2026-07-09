class Solution {
public:
    bool bst(TreeNode* root,long mini,long maxi){
        if(root==NULL)
        {
            return true;
        }
        if(root->val>=maxi || root->val<=mini) return false;
        return bst(root->left,mini,root->val) && bst(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return bst(root,LONG_MIN,LONG_MAX);
    }
};

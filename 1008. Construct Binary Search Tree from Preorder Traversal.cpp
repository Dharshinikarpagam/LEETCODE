class Solution {
public:
    TreeNode* build(vector<int>& p,int& i,int bound)
    {
        if(i==p.size()||p[i]>bound) return NULL;
        TreeNode* root=new TreeNode(p[i++]);
        root->left=build(p,i,root->val);
        root->right=build(p,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};

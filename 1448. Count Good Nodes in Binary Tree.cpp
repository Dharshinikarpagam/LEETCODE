
class Solution {
public:
    int solve(TreeNode* root,int maxsofar)
    {
        if(!root) return 0;
        int cnt=0;
        if(root->val>=maxsofar) cnt=1;
        maxsofar=max(maxsofar,root->val);
        cnt+=solve(root->left,maxsofar);
        cnt+=solve(root->right,maxsofar);
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};

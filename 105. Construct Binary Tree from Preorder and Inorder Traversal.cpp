class Solution {
public:
    TreeNode* build(vector<int>&preorder,int pst,int pe,vector<int>& inorder,int inst,int ine,map<int,int>& mpp)
    {
        if(pst>pe||inst>ine) return NULL;
        TreeNode* root=new TreeNode(preorder[pst]);
        int inroot=mpp[root->val];
        int nl=inroot-inst;
        root->left=build(preorder,pst+1,pst+nl,inorder,inst,inroot-1,mpp);
        root->right=build(preorder,pst+nl+1,pe,inorder,inroot+1,ine,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};

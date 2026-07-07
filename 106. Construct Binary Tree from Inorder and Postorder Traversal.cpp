class Solution {
public:
    TreeNode* build(vector<int>& inorder,int ins,int ine,vector<int>& postorder,int ps,int pe,map<int,int>& mpp)
    {
        if(ins>ine|| ps>pe)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mpp[root->val];
        int nl=inroot-ins;
        root->left=build(inorder,ins,inroot-1,postorder,ps,ps+nl-1,mpp);
        root->right=build(inorder,inroot+1,ine,postorder,ps+nl,pe-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode* root=build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
};

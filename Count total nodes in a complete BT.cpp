class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return 1+left+right;
    }
};

//for perfect or complete binary tree
#include<cmath>
class Solution {
public:
    int lefh(TreeNode* root)
    {
        int h=0;
        while(root)
        {
            h++;
            root=root->left;
        }
        return h;
    }
    int righ(TreeNode* root)
    {
        int h=0;
        while(root)
        {
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lh=lefh(root);
        int rh=righ(root);
        if(lh==rh) return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

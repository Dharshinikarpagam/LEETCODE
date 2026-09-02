class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
         int cnt=0;
         int ans=-1;
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {   cnt++;
            if(cnt==k)
                ans= cur->val;
            
            cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k)
                        ans= cur->val;
                    cur=cur->right;
                }
            }
        }
     return ans;
    }

//next soln
class Solution {
public:
    int ans=-1;
    int cnt=0;
    void inorder(TreeNode* root,int k){
        if(!root) return;
        inorder(root->left,k);
        cnt++;
        if(cnt==k) {
            ans=root->val;
            return;
        }
        inorder(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root==NULL)
        {
            return true;
        }
        if(root->left ==NULL && root->right==NULL)
        {
            return true;
        }
        int sum=0;
        if(root->left)
        {
            sum+=root->left->data;
        }
        if(root->right)
        {
            sum+=root->right->data;
        }
        return (root->data==sum)&& isSumProperty(root->left)&&isSumProperty(root->right);
        
    }
};

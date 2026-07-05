class Solution {
  public:
    bool isLeaf(Node* node)
    {
        if(node->left==NULL && node->right==NULL){
            return true;
        }
        return false;
            
    }
    void lb(Node* root,vector<int>& res)
    {
        Node* cur=root->left;
        while(cur)
        {
            if(!isLeaf(cur)){
                res.push_back(cur->data);
            }
            if(cur->left) 
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }
    }
    void rb(Node* root,vector<int>& res)
    {
        Node* cur=root->right;
        vector<int> temp;
        while(cur)
        {
            if(!isLeaf(cur))
            {
                temp.push_back(cur->data);
            }
            if(cur->right)
            {
                cur=cur->right;
            }
            else{
                cur=cur->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            res.push_back(temp[i]);
        }
    }
    void leaves(Node* root,vector<int>& res)
    {
        if(isLeaf(root))
        {
            res.push_back(root->data);
            return ;
        }
        if(root->left){
            leaves(root->left,res);}
        if(root->right){
            leaves(root->right,res);}
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        lb(root,res);
        leaves(root,res);
        rb(root,res);
        return res;
        
    }
};

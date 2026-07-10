class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        Node* suc=NULL;
        while(root!=NULL)
        {
            if(k->data >= root->data)
            {
                root=root->right;
            }
            else{
                suc=root;
                root=root->left;
            }
        }
        if(suc==NULL)
        {
            return -1;
        }
        return suc->data;
        
    }
};

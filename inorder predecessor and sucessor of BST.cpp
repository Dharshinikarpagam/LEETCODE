class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* suc=NULL;
        Node* pre=NULL;
        Node* temp=root;
        while(temp!=NULL)
        {
            if(key<=temp->data)
            {
                temp=temp->left;
            }
            else{
                pre=temp;
                temp=temp->right;
            }
        }
        temp=root;
        while(temp!=NULL)
        {
            if(key>=temp->data)
            {
                temp=temp->right;
            }
            else{
                suc=temp;
                temp=temp->left;
            }
        }
        return {pre,suc};
    }
};

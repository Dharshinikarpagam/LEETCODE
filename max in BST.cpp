class Solution {
  public:
    int minValue(Node* root) {
      while(root->right!=NULL){
          root=root->right;
      }
      return root->data;
        
        
    }
};

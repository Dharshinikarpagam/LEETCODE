class Solution {
  public:
    int kthLargest(Node *root, int k) {
        int cnt=0;
         int ans=-1;
        Node* cur=root;
        while(cur!=NULL)
        {
            if(cur->right==NULL)
            {   cnt++;
            if(cnt==k)
                ans= cur->data;
            
            cur=cur->left;
            }
            else{
                Node* prev=cur->right;
                while(prev->left && prev->left!=cur)
                {
                    prev=prev->left;
                }
                if(prev->left==NULL)
                {
                    prev->left=cur;
                    cur=cur->right;
                }
                else{
                    prev->left=NULL;
                    cnt++;
                    if(cnt==k)
                        ans= cur->data;
                    cur=cur->left;
                }
            }
        }
     return ans;
        
    }
};

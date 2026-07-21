class BSTIterator {
     stack<TreeNode*> st;
     bool rev=true;
public:
    BSTIterator(TreeNode* root,bool isrev) {
        rev=isrev;
        pushall(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(!rev){
            pushall(temp->right);
        }
        else{
            pushall(temp->left);
        }
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private: 
    void pushall(TreeNode* node)
    {
        for(;node!=NULL;){
            st.push(node);
            if(rev==true){
                node=node->right;
            }
            else{
            node=node->left;
            }
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k)
            {
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
    }
};

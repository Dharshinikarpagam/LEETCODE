class Node1{
public:
    int minnode,maxnode,maxsize;
    Node1(int minnode,int maxnode,int maxsize)
    {
        this->minnode=minnode;
        this->maxnode=maxnode;
        this->maxsize=maxsize;
    }
};
class Solution {
public:
    Node1 lbst(Node* root)
    {
        if(!root)
        {
            return Node1(INT_MAX,INT_MIN,0);
        }
        auto left=lbst(root->left);
        auto right=lbst(root->right);
        if(left.maxnode<root->data && root->data < right.minnode)
        {
            return Node1(min(root->data,left.minnode),max(root->data,right.maxnode),left.maxsize+right.maxsize+1);
        }
        return Node1(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
    }

    int largestBst(Node *root) {
        
        return lbst(root).maxsize;
    }
};

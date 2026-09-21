class Solution {
private:
    unordered_map<Node*,Node*> mp;
    Node* dfs(Node* node)
    {
        if(mp.find(node)!=mp.end())
        {
            return mp[node];
        }
        Node* clone=new Node(node->val);
        mp[node]=clone;
        for(auto it:node->neighbors)
        {
            clone->neighbors.push_back(dfs(it));
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        return dfs(node);
    }
};

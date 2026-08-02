class Solution {
  public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &cur)
    {
        vis[node]=1;
        cur.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,cur);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> cur;
        vector<int> vis(V,0);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,cur);
                ans.push_back(cur);
                cur={};
            }
        }
        return ans;
        
    }
};

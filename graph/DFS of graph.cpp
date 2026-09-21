class Solution {
  private:
    void dfsg(int node,vector<vector<int>>& adj,int vis[],vector<int>& ls)
    {
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it]){
             dfsg(it,adj,vis,ls);
           }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int v=adj.size();
        int vis[v]={0};
        int start=0;
        vector<int> ls;
        dfsg(start,adj,vis,ls);
        return ls;
        
    }
};

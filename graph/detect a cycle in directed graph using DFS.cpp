class Solution {
  private:
    bool cycle(int node,vector<int>& vis,vector<int>& dfsvis,vector<vector<int>>& adj)
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(cycle(it,vis,dfsvis,adj))
                {
                    return true;
                }
            }
            else if(dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
       vector<int> vis(V,0);
       vector<int> dfsvis(V,0);
       vector<vector<int>> adj(V);
       for(auto it: edges)
       {
           adj[it[1]].push_back(it[0]);
       }
       for(int i=0;i<V;i++)
       {
           if(!vis[i])
           {
               if(cycle(i,vis,dfsvis,adj))
               {
                   return true;
               }
           }
       }
       return false;
        
    }
};

class solution{
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<int> ind(V,0);
       queue<int> q;
       vector<vector<int>> adj(V);
       for(auto it:edges)
       {
           adj[it[0]].push_back(it[1]);
       }
       for(int i=0;i<V;i++)
       {
           for(auto it:adj[i])
           {
               ind[it]++;
           }
       }
       for(int i=0;i<V;i++)
       {
           if(ind[i]==0)
           {
               q.push(i);
           }
       }
       vector<int> ans;
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(auto it:adj[node])
           {
               ind[it]--;
               if(ind[it]==0)
               {
                   q.push(it);
               }
           }
       }
       return ans;
        
    }
};

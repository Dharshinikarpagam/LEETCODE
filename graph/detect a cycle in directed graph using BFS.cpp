class Solution {
 public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
       vector<vector<int>> adj(V);
       int ind[V]={0};
       for(auto it: edges)
       {
           adj[it[1]].push_back(it[0]);
       }
       for(int i=0;i<V;i++)
       {
           for(auto it:adj[i])
           {
               ind[it]++;
           }
       }
       queue<int> q;
       for(int i=0;i<V;i++)
       {
           if(ind[V]==0)
           {
               q.push(i);
           }
       }
       int cnt=0;
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           cnt++;
           for(auto it:adj[node])
           {
               ind[it]--;
               if(ind[it]==0)
               {
                   q.push(it);
               }
           }
       }
       if(cnt==V)
       {
           return false;
       }
       return true;
        
    }
};

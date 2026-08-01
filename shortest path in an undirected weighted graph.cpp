class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
       vector<vector<pair<int,int>>> adj(V+1);
       for(auto it: edges)
       {
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
       priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> pq;
        vector<int> dist(V+1,1e9);
        dist[src]=0;
        vector<int> parent(V+1);
        for(int i=0;i<=V;i++)
        {
            parent[i]=i;
        }
        pq.push({0,src});
        while(!pq.empty())
        {
            auto it=pq.top();
            int dis=it.first;
            int node=it.second;
            pq.pop();
            if(dis > dist[node])
                    continue;
            for(auto it:adj[node])
            {
                int edgeweight=it.second;
                int adjnode=it.first;
                if(dis+edgeweight<dist[adjnode])
                {
                    dist[adjnode]=dis+edgeweight;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode]=node;
                }
                
            }
            
        }
        if(dist[dest]==1e9)
        {
            return {-1};
        }
        vector<int> path;
        int node=dest;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        return path;
        
    }
};

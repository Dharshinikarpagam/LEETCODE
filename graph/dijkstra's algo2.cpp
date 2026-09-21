class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dist(V,1e9);
        set<pair<int,int>> st;
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty())
        {
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second;
            st.erase(it);
            for(auto it: adj[node])
            {
                int edgeweight=it.second;
                int adjnode=it.first;
                if(dis+edgeweight<dist[adjnode])
                {
                    if(dist[adjnode]!=1e9)
                    {
                        st.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+edgeweight;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};

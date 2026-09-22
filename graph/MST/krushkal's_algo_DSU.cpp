class DSU {
    vector<int> rank,parent,size1;
public:
    DSU(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size1.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size1[i]=1;
        }
    }
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
  // to get a connection y rank
    void unionByRank(int u, int v) {
        int upu=find(u);
        int upv=find(v);
        if(upu==upv){
            return;
        }
        if(rank[upu]<rank[upv])
        {
            parent[upu]=upv;
        }
        else if(rank[upv]<rank[upu])
        {
            parent[upv]=upu;
        }
        else{
            parent[upv]=upu;
            rank[upu]++;
        }
    }
  // to get a connection by size
    void unionBySize(int u, int v) {
        int upu=find(u);
        int upv=find(v);
        if(upu==upv){
            return;
        }
        if(size1[upu]<size1[upv])
        {
            parent[upu]=upv;
            size1[upv]+=size1[upu];
        }
        else
        {
            parent[upv]=upu;
            size1[upu]+=size1[upv];
        }
    }
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        DSU ds(V);
        sort(edges.begin(),edges.end(),[](vector<int>& a,vector<int> &b)
        {
           return a[2]<b[2];
        }
        );
        int mstwt=0;
        for(auto it :edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(ds.find(u)!=ds.find(v)){
                mstwt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
};

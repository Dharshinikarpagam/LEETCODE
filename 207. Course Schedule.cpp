class Solution {
private:
    bool cycle(int node,vector<int>& vis,vector<int>& dfsvis,vector<vector<int>>& adj)
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it: adj[node])
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> dfsvis(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(cycle(i,vis,dfsvis,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int>visited(n,0);

        return dfs(source,adj,source,destination,visited);
    }
    bool dfs(int curr,vector<vector<int>>&adj,int src,int dest,vector<int>&visited){
        if(dest==curr) return true;

        //mark visited
        visited[curr]=1;

        for(auto neighbour: adj[curr]){
            if(visited[neighbour]!=1){
                if(dfs ( neighbour,adj,src,dest,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    void dfs(int s,int d,vector<vector<int>> &adj, vector<int> &vis){
        vis[s]=1;
        for(auto i:adj[s]){
            if(!vis[i]){
                dfs(i,d,adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
        }
        vector<int> vis(n,0);
        dfs(source,destination,adj,vis);
        return vis[destination];
    }
};
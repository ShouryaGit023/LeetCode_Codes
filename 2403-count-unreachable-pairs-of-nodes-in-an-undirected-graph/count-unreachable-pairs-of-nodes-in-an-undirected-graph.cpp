class Solution {
public:
    void dfs(int u,vector<int> &vis, vector<vector<int>> &adj, unordered_map<int,int> &m,int cc,vector<int> &idcc){
        idcc[u]=cc;
        vis[u]=1;
        m[cc]++;
        for(auto v:adj[u]){
            if(!vis[v]){
                dfs(v,vis,adj,m,cc,idcc);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& e) {
        vector<vector<int>>adj(n);
        for(auto i:e){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        vector<int> idcc(n,0);
        unordered_map<int,int> m;
        int cc=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,m,cc,idcc);
                cc++;
            }
        }
        for(auto i:m){

        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int same=m[idcc[i]];
            ans+=n-same;
        }
        return ans/2;
        
    }
};
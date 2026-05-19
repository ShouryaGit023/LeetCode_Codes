class Solution {
public:
    void dfs(int start,vector<vector<int>> &adj, vector<int> &vis){
        vis[start]=1;
        for(auto i:adj[start]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
        
    }
};
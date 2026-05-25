class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj, vector<int> &color){
        for(auto v:adj[i]){
            if(color[v]==-1){
                color[v]=3-color[i];
                dfs(v,adj,color);
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> adj(n);
        for(auto i:d){
            int u=i[0]-1;
            int v=i[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=1;
                dfs(i,adj,color);
            }
        }

        bool check= true;
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                if(color[i]==color[j]){
                    check=false;
                    break;
                }
            }
        }
        return check;
        
    }
};
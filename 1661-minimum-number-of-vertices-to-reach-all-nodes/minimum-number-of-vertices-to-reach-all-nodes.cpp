class Solution {
public:
   
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            vis[e[1]]++;
        }
        vector<int> nodes;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                nodes.push_back(i);
            }
        }
        return nodes;
        
    }
};
class Solution {
public:
   
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        
        for(auto e:edges){
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
class Solution {
public:
    bool dfs(int i,vector<vector<int>> &v,vector<int> &vis){
        vis[i]=1;
        for(auto u:v[i]){
            if(vis[u]==1)return true;
            if(vis[u]==0 && dfs(u,v,vis))return true;
        }
        vis[i]=2;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        for(auto i:p){
            v[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        bool cycle=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cycle|=dfs(i,v,vis);
            }
        }
        return !cycle;
        
    }
};
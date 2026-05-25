class Solution {
public:
    bool hasCycle(int i,vector<int> &vis,vector<vector<int>> &v){
        vis[i]=1;
        for(auto u:v[i]){
            if(vis[u]==1){
                return true;
            }
            if (vis[u] == 0 && hasCycle(u, vis, v)) return true;
        }
        vis[i]=2;
        return false;
    }
    void topoDfs(int i,vector<int>& an,vector<vector<int>> &v, vector<int> &t){
        an[i]=1;
        for(auto u:v[i]){
            if(!an[u]){
                topoDfs(u,an,v,t);
            }
        }
        t.push_back(i);
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        for(auto i:p){
            v[i[1]].push_back(i[0]);
        }

        //check for cycle
        vector<int> vis(n,0);
        bool cycle=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cycle|=hasCycle(i,vis,v);
            }
        }
        if(cycle){
            return {};
        }
        vector<int> an(n,0);
        vector<int> topo;
        for(int i=0;i<n;i++){
            if(!an[i])
        topoDfs(i,an,v,topo);
        }
        reverse(topo.begin(),topo.end());
        return topo;
        
    }
};
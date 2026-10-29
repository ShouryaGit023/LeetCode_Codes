class Solution {
public:
    vector<int> sz,dis,ans;
    void dfs1(int node, int par,vector<vector<int>> &adj){
        for(auto i:adj[node]){
            if(i!=par){
                dfs1(i,node,adj);
            }
        }
        for(auto i:adj[node]){
            if(i!=par){
                sz[node]+=sz[i];
                dis[node]+=dis[i]+sz[i];
            }
        }
    }
    void dfs2(int node, int par, vector<vector<int>>&adj,int n){
        for(auto i:adj[node]){
            if(i!=par){
                ans[i]=ans[node]-sz[i]+(n-sz[i]);
                dfs2(i,node,adj,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        sz.resize(n,1);
        dis.resize(n);
        ans.resize(n);
        vector<vector<int>> v(n);
        for(auto i:edges){
            v[i[1]].push_back(i[0]);
            v[i[0]].push_back(i[1]);
        }
        dfs1(0,-1,v);
        ans[0]=dis[0];
        dfs2(0,-1,v,n);
        return ans;
    }
};
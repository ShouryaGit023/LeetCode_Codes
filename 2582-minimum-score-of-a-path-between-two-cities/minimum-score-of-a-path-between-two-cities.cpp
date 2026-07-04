class Solution {
public:
    int minScore(int n, vector<vector<int>>& v) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:v){
            int u=i[0];
            int v=i[1];
            int c=i[2];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        queue<int> q;
        vector<int> dis(n+1,INT_MAX);
        q.push(1);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                if(dis[i.first]>min(i.second,dis[node])){
                    dis[i.first]=min(i.second,dis[node]);
                    q.push(i.first);
                }
            }
        }
        return dis[n];

    }
};
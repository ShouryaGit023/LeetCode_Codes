class Solution {
public:
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        int dest=n-1;
        vector<vector<pair<int,long long>>>adj(n+1);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int> paths(n+1,0);
        vector<long long> minT(n+1,LLONG_MAX);
        minT[0]=0;
        paths[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>p;
        p.push({0,0});// time,node;
        while(!p.empty()){
            auto [ct,cn]=p.top();
            p.pop();
            if(ct>minT[cn])continue;
            for(auto i:adj[cn]){
                auto [nn,nt]=i;
                long long newT=nt+ct;
                if(newT<minT[nn]){
                    minT[nn]=newT;
                    paths[nn]=paths[cn];
                    p.push({minT[nn],nn});
                }
                else if(newT==minT[nn]){
                    paths[nn]=(paths[cn]+paths[nn])%MOD;
                }
            }
        }
        return paths[n-1];     }
};
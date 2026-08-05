class Solution {
public:
    bool check=false;
    set<int> s;
    void dfs(int node,vector<vector<int>> &v, vector<bool> &take, bool &w,vector<int> &vis){
        s.insert(node);
        if(take[node]==false)check=true;
        take[node]=w;
        vis[node]=1;
        for(auto i:v[node]){
            if(!vis[i])
            dfs(i,v,take,w,vis);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> take(n,true);
        vector<vector<int>> v(n);
        vector<int> vis(n,0);
        for(auto i:invocations){
            v[i[0]].push_back(i[1]);
        }
        bool w=false;
        dfs(k,v,take,w,vis);
        for(auto &i:vis){
            i=0;
        }
        bool c=true;
        for(int i=0;i<n;i++){
            if(s.count(i)==0 && !vis[i]){
                dfs(i,v,take,c,vis);
            }
        }
        vector<int> ans;
         if(check){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        else {for(int i=0;i<n;i++){
            if(take[i]){
                ans.push_back(i);
            }
        }}
        return ans;

        
    }
};
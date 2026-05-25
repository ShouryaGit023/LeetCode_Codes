class Solution {
public:
    void dfs(int i,vector<vector<int>> &adj, vector<int> &vis){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(j,adj,vis);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& b) {
        int n=b.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int prev_r=b[i][2];
            int prev_x=b[i][0];
            int prev_y=b[i][1];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int curr_x=b[j][0];
                int curr_y=b[j][1];

                //check if inside this bombs explosion or not
                long long dx = (long long)prev_x - curr_x;
                long long dy = (long long)prev_y - curr_y;
                long long r = prev_r;
                if (dx * dx + dy * dy <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }
        int max_e=1;
        for(int i=0;i<n;i++){
            //expload the first one and check how many exploded with it
            vector<int> vis(n,0);
            dfs(i,adj,vis);
            int c=0;
            for(auto j:vis){
                if(j)c++;
            }
            max_e=max(max_e,c);
        }
        return max_e;



        
    }
};
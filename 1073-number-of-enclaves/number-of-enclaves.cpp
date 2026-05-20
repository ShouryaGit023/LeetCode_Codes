class Solution {
public:
    void dfs(int i, int j,vector<vector<int>> &v, vector<vector<int>> &vis, int n, int m){
        vis[i][j]=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(ny>=0 && ny<m && nx>=0 && nx<n && !vis[nx][ny] && v[nx][ny]==1){
                dfs(nx,ny,v,vis,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && v[i][0]==1){
                dfs(i,0,v,vis,n,m);
            }
            if(!vis[i][m-1] && v[i][m-1]==1){
                dfs(i,m-1,v,vis,n,m);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[0][i] && v[0][i]==1){
                dfs(0,i,v,vis,n,m);
            }
            if(!vis[n-1][i] && v[n-1][i]==1){
                dfs(n-1,i,v,vis,n,m);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && v[i][j]==1)ans++;
            }
        }
        return ans;
        
    }
};
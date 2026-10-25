class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void dfs(int i,int j, int n,int m,vector<vector<int>> &vis, vector<vector<int>> &v){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && v[ni][nj]==0){
                dfs(ni,nj,n,m,vis,v);
            }
        }
    }
    int closedIsland(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && v[i][0]==0){
                dfs(i,0,n,m,vis,v);
            }
            if(!vis[i][m-1] && v[i][m-1]==0){
                 dfs(i,m-1,n,m,vis,v);
            }
        }
        for(int j=0;j<m-1;j++){
            if(!vis[0][j] && v[0][j]==0){
                dfs(0,j,n,m,vis,v);
            }
            if(!vis[n-1][j] && v[n-1][j]==0){
                 dfs(n-1,j,n,m,vis,v);
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && v[i][j]==0){
                    ans++;
                    dfs(i,j,n,m,vis,v);
                }
            }
        }
        return ans;
    }
};
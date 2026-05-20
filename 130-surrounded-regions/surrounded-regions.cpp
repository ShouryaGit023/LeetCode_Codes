class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &v,int n,int m,vector<vector<int>> &vis){
        vis[i][j]=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && v[nx][ny]=='O'){
                if(!vis[nx][ny]){
                dfs(nx,ny,v,n,m,vis);
                }
            }
        }
        
        return;
    }
    void solve(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && v[i][0]=='O'){
                dfs(i,0,v,n,m,vis);
            }
             if(!vis[i][m-1] && v[i][m-1]=='O'){
                dfs(i,m-1,v,n,m,vis);
             }
        }  
        for(int i=0;i<m;i++){
            if(!vis[0][i] && v[0][i]=='O'){
                dfs(0,i,v,n,m,vis);
            }
             if(!vis[n-1][i]  && v[n-1][i]=='O'){
                dfs(n-1,i,v,n,m,vis);
             }
        }  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && v[i][j]=='O'){
                    v[i][j]='X';
                }
            }
        }
    }
};
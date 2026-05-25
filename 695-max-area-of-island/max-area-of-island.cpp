class Solution {
public:
    int ans=0;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>> &v,vector<vector<int>> &vis,int &c){
        c++;
        ans=max(ans,c);
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<v.size() && nj<v[0].size() && !vis[ni][nj] && v[ni][nj]==1){
                dfs(ni,nj,v,vis,c);
            }
        }


    }

    int maxAreaOfIsland(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            int c=0;
                if(!vis[i][j] && v[i][j]==1){
                    dfs(i,j,v,vis,c);
                }
            }
        }
        return ans;
        
    }
};
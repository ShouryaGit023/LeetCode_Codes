class Solution {
public:
    int di[4]={0,0,1,-1};
    int dj[4]={-1,1,0,0};
    void dfs(int i,int j,int n,int m,vector<vector<int>> &vis,vector<vector<int>> &v,long long &sum){
        vis[i][j]=1;
        sum+=v[i][j];
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>=0 && nj>=0 && nj<m && ni<n && !vis[ni][nj] && v[ni][nj]!=0){
                dfs(ni,nj,n,m,vis,v,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && v[i][j]!=0){
                    long long sum=0;
                    dfs(i,j,n,m,vis,v,sum);
                if(sum%k==0)ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]==1 && ans[x][y]+1<ans[nx][ny]){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push({nx,ny});
                }
            }

        }
        return ans;

    }
};
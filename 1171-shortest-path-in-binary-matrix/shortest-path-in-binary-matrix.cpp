class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        if(v[0][0]==1)return -1;
        int n=v.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});

        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<8;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];

                if(nx>=0 && ny>=0 && ny<n && nx<n && v[nx][ny]==0){
                    if(dis[nx][ny]>dis[i][j]+1){
                        dis[nx][ny]=dis[i][j]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        if(dis[n-1][n-1]==INT_MAX)return -1;
        return dis[n-1][n-1];
    }
};
class Solution {
public:
    bool containsCycle(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    queue<vector<int>>q;
                    q.push({-1,-1,i,j}); //px,py, nx,ny
                    vis[i][j]=1;
                     while( !q.empty()){
            int px=q.front()[0];
            int py=q.front()[1];
            int cx=q.front()[2];
            int cy=q.front()[3];
            q.pop();
            for(int k=0;k<4;k++){
                int nx=cx+dx[k];
                int ny=cy+dy[k];
                if(ny>=0 && ny<m && nx>=0 && nx<n && v[cx][cy]==v[nx][ny]){
                    if(!vis[nx][ny]){
                        q.push({cx,cy,nx,ny});
                        vis[nx][ny]=1;
                    }
                    else{
                        if(nx==px && ny==py)continue;
                        else {
                            return true;
                        }
                    }
                }
            }

        }       
                }
            }
        }
        
            return false;
    }
};
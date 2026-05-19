class Solution {
public:
    bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> c(n,-1);
        for(int i=0;i<n;i++){
            if(c[i]==-1){
                queue<int> q;
                q.push(i);
                c[i]=0;
                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    for(auto j:v[u]){
                        if(c[j]==-1){
                            c[j]=1-c[u];
                            q.push(j);
                        }
                        else if(c[j]==c[u]){
                            return false;
                        }
                    }

                }
            }
        }
        return true;
        
    }
};
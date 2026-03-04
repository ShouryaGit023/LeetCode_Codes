class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> ro(m,0);
        vector<int> co(n,0);
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)c++;
            }
            ro[i]=c;
        }
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                if(mat[j][i]==1)c++;
            }
            co[i]=c;
        }

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && co[j]==1 && ro[i]==1){
                    ans++;
                }
            }
        }
        return ans;

        
    }
};
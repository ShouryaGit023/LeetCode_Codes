class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<char>> ans(m,vector<char>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][n - 1 - i] = v[i][j];
            }
        }
        for(int j=0;j<n;j++){
            for(int i=m-2;i>=0;i--){
                if(ans[i][j]=='#'){

                
                int k=i;
                while(k<=m-2 && ans[k+1][j]=='.'){
                    swap(ans[k][j],ans[k+1][j]);
                    k++;
                }
                }
            }
        }
        return ans;
    }
};
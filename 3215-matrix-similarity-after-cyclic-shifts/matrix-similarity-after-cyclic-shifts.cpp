class Solution {
public:
    bool areSimilar(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]!=v[i][(j+k)%m]){
                    return false;
                }
            }
            
        }
            return true;
    }
};
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> ve=v;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
            ve[i][j]+=ve[i][j-1];}
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                ve[i][j]+=ve[i-1][j];
            }
        }
        int ans=0;
        for(auto i:ve){
            for(auto j:i){
                
                if(j<=k)ans++;
            }
            
        }
        return ans;
        
        
    }
};
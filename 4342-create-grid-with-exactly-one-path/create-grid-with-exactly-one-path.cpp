class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> v(m,string(n,'#'));
        for(int i=0;i<n;i++){
            v[0][i]='.';
        }
        for(int i=0;i<m;i++){
            v[i][n-1]='.';
        }
        
        return v;
        
    }
};
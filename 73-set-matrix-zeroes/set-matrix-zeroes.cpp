class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        unordered_set<int> r,c;
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(r.count(i) || c.count(j)){
                    v[i][j]=0;
                }
            }
        }
    
        
    }
};
class Solution {
public:
    vector<vector<int>> r9(vector<vector<int>> &v){
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                swap(v[i][j],v[j][i]);
            }
        }
        for(int i=0;i<v.size();i++){
            reverse(v[i].begin(),v[i].end());
        }
        return v;
    }
    bool findRotation(vector<vector<int>>& v, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            if(v == target) return true; // Check if current state matches
            r9(v);                 // Rotate for the next check
        }
        return false;
        
    }
};
class Solution {
public:
    bool areSimilar(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> v2=v;
        for(int i=0;i<n;i++){
            vector<int> temp=v[i];
            // cout<<temp.size()<<endl;
            // for(auto k:temp){
            //     cout<<k<<" ";
            // }
        
            if (i & 1) { 
    // ODD row: Right shift by k
    for (int j = 0; j < m; j++) {
        v[i][j] = temp[(m + (j - k) % m) % m];
    }
} 
else { 
    // EVEN row: Left shift by k
    for (int j = 0; j < m; j++) {
        v[i][j] = temp[(j + k) % m];
    }
}
            

        }
        return v2==v;
    }
};
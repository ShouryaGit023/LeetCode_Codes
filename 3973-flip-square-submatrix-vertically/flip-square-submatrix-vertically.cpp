class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& v, int x, int y, int k) {
        for(int i=y;i<k+y;i++){
            int l=x,r=x+k-1;
            while(l<r){
                swap(v[l][i],v[r][i]);
                l++;
                r--;
            }
        }
        
        return v;
    }
};
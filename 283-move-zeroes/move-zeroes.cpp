class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n=v.size();
        int l=0;
        for(int r=0;r<n;r++){
            if(v[r]!=0){
                swap(v[r],v[l]);
                l++;
            }
        }
        
    }
};
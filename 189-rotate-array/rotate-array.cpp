class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n=v.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[(i+k)%n]=v[i];
        }
        v=ans;
        
    }
};
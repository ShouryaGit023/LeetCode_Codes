class Solution {
public:
    int minMoves2(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int med=v[n/2];
        int ans=0;
        for(auto i:v){
            ans+=abs(i-med);
        }
        return ans;
        
    }
};
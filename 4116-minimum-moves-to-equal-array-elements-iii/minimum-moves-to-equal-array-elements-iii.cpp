class Solution {
public:
    int minMoves(vector<int>& v) {
        int mx=*max_element(v.begin(),v.end());
        int ans=0;
        for(auto i:v){
            ans+=(abs(i-mx));
        }
        return ans;
        
    }
};
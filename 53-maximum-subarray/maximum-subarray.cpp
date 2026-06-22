class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int ms=v[0];
        int cs=0;
        for(auto i:v){
            cs+=i;
            ms=max(cs,ms);
            if(cs<0)cs=0;
        }
        return ms;
    }
};
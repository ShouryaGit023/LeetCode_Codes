class Solution {
public:
    int findFinalValue(vector<int>& v, int o) {
        int n=v.size();
        sort(v.begin(),v.end());
        for(auto i:v){
            if(i==o)o*=2;
        }
        return o;
        
    }
};
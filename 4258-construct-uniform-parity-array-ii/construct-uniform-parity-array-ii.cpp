class Solution {
public:
    bool uniformArray(vector<int>& v) {
        int n=v.size();
        int m=v[0];
        bool o=false;
        for(auto i:v){
            if(i<m){
                m=i;
            }
            if(i%2!=0){
                o=true;
            }
        }
        if(!o){
            return true;
        }
        if(m%2!=0){
            return true;
        }
        return false;
        
    }
};
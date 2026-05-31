class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        sort(a.begin(),a.end());
        long long ma=m;
        for(auto i:a){
            if(ma>=i){
                ma+=i;
            }
            else{
                return false;
            }
            
        }
        return true;

        
    }
};
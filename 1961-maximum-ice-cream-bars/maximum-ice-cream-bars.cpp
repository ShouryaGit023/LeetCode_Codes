class Solution {
public:
    int maxIceCream(vector<int>& v, int coins) {
        sort(v.begin(),v.end());
        int ans=0;
        for(auto i:v){
            if(coins>=i){
                ans++;;
                coins-=i;
            }
        }
        return ans;
        
    }
};
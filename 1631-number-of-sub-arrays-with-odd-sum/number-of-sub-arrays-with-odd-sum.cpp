class Solution {
public:
    int numOfSubarrays(vector<int>& v) {
        int o=0;
        const int mod=1e9+7;
        int e=1;
        int ans=0;
        int pr=0;
        for(auto i:v){
            pr+=i;
            if(pr&1){
                ans+=e;
                o++;
            }
            else{
                ans+=o;
                e++;
            }
            ans%=(mod);
        }
        return ans;
        
    }
};
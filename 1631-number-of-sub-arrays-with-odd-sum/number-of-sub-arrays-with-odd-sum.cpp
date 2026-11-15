class Solution {
public:
    int numOfSubarrays(vector<int>& v) {
        int n=v.size();
        int e=1;
        int o=0;
        int ans=0;
        int ps=0;
        const int MOD=1e9+7;
        for(int i=0;i<n;i++){
            ps+=v[i];
            if(ps&1){
                ans+=e;
                o++;
            }
            else{
                ans+=o;
                e++;
            }
            ans%=MOD;
        }
        return ans;
    }
};
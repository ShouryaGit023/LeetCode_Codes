class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        int m=1e8;
        int ans=-1e9;
        for(int i=0;i<n;i++){
            ans=max(ans,v[i]-m);
            m=min(v[i],m);
        }
        return max(0,ans);

        
    }
};
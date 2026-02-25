class Solution {
public:
    int maxAdjacentDistance(vector<int>& v) {
        int n=v.size();
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,abs(v[i]-v[i-1]));
        }        
        ans=max(ans,abs(v[0]-v[n-1]));
        return ans;
    }
};
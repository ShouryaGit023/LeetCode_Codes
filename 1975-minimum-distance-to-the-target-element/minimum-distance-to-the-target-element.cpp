class Solution {
public:
    int getMinDistance(vector<int>& v, int t, int s) {
        int n=v.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(v[i]==t){
                ans=min(ans,abs(i-s));
            }
        }

    return ans;
        
    }
};
class Solution {
public:
    int maxDistance(vector<int>& v) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]!=v[j]){
                    ans=max(ans,j-i);
                }
            }
        }
        return ans;
    }
};
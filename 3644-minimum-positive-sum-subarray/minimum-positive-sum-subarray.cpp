class Solution {
public:
    int minimumSumSubarray(vector<int>& v, int l, int r) {
        int n=v.size();
        long long ans=INT_MAX;
        for(int i=0;i<n;i++){
            long long s=0;
            for(int j=i;j<n && j-i+1<=r;j++){
                s+=v[j];
            if(j-i+1>=l && s>0)ans=min(ans,s);
            }
            
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
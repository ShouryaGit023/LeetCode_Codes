class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int n=v.size();
        int l=1;
        int r=2000;
        int ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            auto it=m-(upper_bound(v.begin(),v.end(),m)-v.begin());
            if(it>=k){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
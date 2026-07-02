class Solution {
public:
    bool check(vector<int> &v, int k, long long mid){
        int c=1;
        long long s=0;
        for(auto i:v){
            if(i>mid)return false;
            if(i+s<=mid){
                s+=i;
            }
            else{
                s=i;
                c++;
            }
        }
        return c<=k;
    }
    int splitArray(vector<int>& v, int k) {
        int n=v.size();
        long long l=0;
        long long r=1e18;
        int ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(v,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
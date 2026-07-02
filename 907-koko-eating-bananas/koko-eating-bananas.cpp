class Solution {
public:
    bool check(vector<int> &v,int mid,int h){
        long long t=0;
        for(auto i:v){
            t+=(i+mid-1)/mid;
        }
        return t<=h;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int n=v.size();
        int ans=0;
        int l=1;
        int r=1e9;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(v,m,h)){
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
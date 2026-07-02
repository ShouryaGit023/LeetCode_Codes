class Solution {
public:
    bool check(vector<int>&v, int mid, int day){
        int d=1;
        int s=0;
        for(auto i:v){
            if(i>mid)return false;
            if(s+i<=mid)s+=i;
            else{
                s=i;
                d++;
            }
        }
        return d<=day;

    }
    int shipWithinDays(vector<int>& v, int d) {
        int n=v.size();
        int l=1;
        int r=1e9;
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(v,m,d)){
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
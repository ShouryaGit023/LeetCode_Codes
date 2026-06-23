class Solution {
public:
    static bool check(int m,vector<int> &v,int t){
        int s=0;
        for(auto i:v){
            s+=(i+(m-1))/m;
        }
        return t>=s;
    }
    int smallestDivisor(vector<int>& v, int t) {
        int n=v.size();
        int l=1,r=1e6;
        int ans=1;
        while(l<=r){
            int m=(r+l)/2;
            if(check(m,v,t)){
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
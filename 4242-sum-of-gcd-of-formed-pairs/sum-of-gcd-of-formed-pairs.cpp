class Solution {
public:
    int gcd(int a,int b){
        return b == 0 ? a : gcd(b, a % b); 
    }
    long long gcdSum(vector<int>& v) {
        int mx=v[0];
        vector<int> pg;
        for(auto i:v){
            mx=max(mx,i);
            pg.push_back(gcd(mx,i));
        }
        sort(pg.begin(),pg.end());
        long long ans=0;
        int l=0,r=pg.size()-1;
        while(l<r){
            ans+=(gcd(pg[l],pg[r]));
            l++;
            r--;
        }
        return ans;
    }
};
class Solution {
public:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
    int maxLength(vector<int>& v) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            long long p=1;
            int l=v[i];
            int g=v[i];
            
            for(int j=i;j<n;j++){
                p=(p*1LL*v[j])%1000000007;
                l=lcm(l,v[j]);
                g=gcd(g,v[j]);

                if(p==(l*g)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
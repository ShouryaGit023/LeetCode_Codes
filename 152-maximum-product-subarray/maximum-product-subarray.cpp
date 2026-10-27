class Solution {
public:
    int maxProduct(vector<int>& v) {
        int mx=INT_MIN;
        int n=v.size();
        int p=1;
        for(auto i:v){
            p*=i;
            mx=max(mx,p);
            if(p==0)p=1;
        }
        p=1;
        for(auto i=n-1;i>=0;i--){
            p*=v[i];
            mx=max(mx,p);
            if(p==0)p=1;
        }
        return mx;

    }
};
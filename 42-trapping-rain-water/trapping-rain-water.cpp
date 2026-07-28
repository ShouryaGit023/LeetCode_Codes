class Solution {
public:
    int trap(vector<int>& v) {
        vector<int> f;
        int n=v.size();
        int mx=-1;
        for(auto i:v){
            mx=max(mx,i);
            f.push_back(mx);
        }
        vector<int> b(n,0);
        mx=-1;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,v[i]);
            b[i]=mx;
        }
        for(auto i:f){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:b){
            cout<<i<<" ";
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(f[i],b[i]))-v[i];
        }
        return ans;
    }
};
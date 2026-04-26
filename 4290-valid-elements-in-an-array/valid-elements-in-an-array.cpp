class Solution {
public:
    vector<int> findValidElements(vector<int>& v) {
        int n=v.size();
        vector<int> ans(n,0);
        ans[0]=v[0];
        ans[n-1]=v[n-1];
        int lm=v[0];
        for(int i=1;i<n;i++){
            if(v[i]>lm)ans[i]=v[i];
            lm=max(lm,v[i]);
        }
        int rm=v[n-1];
        for(int i=n-2;i>=0;i--){
            if(v[i]>rm)ans[i]=v[i];
            rm=max(rm,v[i]);
        }
        vector<int> res;
        for(auto i:ans){
            if(i!=0)
            res.push_back(i);
        }
        return res;
        
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n=v.size();
        int ps=0;
        int ns=1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(v[i]>0){
                ans[ps]=v[i];
                ps+=2;
            }
            else{
                ans[ns]=v[i];
                ns+=2;
            }
        }
        return ans;
        
    }
};
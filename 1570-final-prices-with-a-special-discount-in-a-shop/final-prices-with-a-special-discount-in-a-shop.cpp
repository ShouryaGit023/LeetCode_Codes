class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        stack<int> s;
        int n=v.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()>v[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(v[i]);
        }
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                ans[i]=v[i];
            }
            else{
                ans[i]=v[i]-ans[i];
            }
        }
        return ans;


    }
};
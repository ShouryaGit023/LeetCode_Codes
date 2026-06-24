class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            v.push_back(v[i]);
        }
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty()  && s.top()<=v[i]){
                s.pop();
            }
            if(s.empty()){
                if(i<=n-1){
                    ans[i]=-1;
                }

            }
            else{
                if(i<=n-1){
                    ans[i]=s.top();
                }
            }
            s.push(v[i]);
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> m;
        int n=b.size();
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<b[i]){
                s.pop();
            }
            if(s.empty()){
                m[b[i]]=-1;
            }
            else{
                m[b[i]]=s.top();
            }
            s.push(b[i]);
        }
    vector<int> ans;
    for(auto i:a){
        ans.push_back(m[i]);
    }
    return ans;
    }
};
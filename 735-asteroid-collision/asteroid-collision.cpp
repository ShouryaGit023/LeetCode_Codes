class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        vector<int> ans;
        int n=v.size();
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(v[i]<0){
                s.push(-v[i]);
                continue;
            }
            bool eq=false;
            while(!s.empty() && s.top()<=v[i]){
                if(s.top()==v[i]){
                    eq=true;
                    s.pop();
                    break;
                }
                s.pop();
            }
            if(s.empty() && !eq){
                ans.push_back(v[i]);
            }
        }
        stack<int> an;
        while(!s.empty()){
            an.push(-s.top());
            s.pop();
        }
        while(!an.empty()){
            ans.push_back(an.top());
            an.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
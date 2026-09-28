class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        for(auto i:s){
            if(i=='('){
                st.push(i);
            }
            else if(i==')'){
                st.pop();
            }
            ans=max(ans,(int)st.size());
        }
        return ans;
    }
};
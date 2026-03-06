class Solution {
public:
    bool checkOnesSegment(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            int top=st.top();
            if(s[i]=='1'){
                if(top=='1'){
                    continue;
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        int c=0;
        while(!st.empty()){
            int t=st.top();
            st.pop();
            if(t=='1')c++;
        }
        return c==1;
        
    }
};
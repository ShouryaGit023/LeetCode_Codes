class Solution {
public:
    bool open(char c){
        return (c=='{' || c=='('|| c=='[');
    }
    bool match(char a,char b){
        return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(open(i)){
                st.push(i);
            }
            else{
                if(st.empty())return false;
                char a=st.top();
                if(match(a,i)){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
       return st.size()==0;
        
    }
};
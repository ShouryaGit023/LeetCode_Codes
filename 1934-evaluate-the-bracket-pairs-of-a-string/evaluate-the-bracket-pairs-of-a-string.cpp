class Solution {
public:
    string evaluate(string s, vector<vector<string>>& v) {
        map<string,string> m;
        for(auto i:v){
            m[i[0]]=i[1];
        }
        stack<char> st;
        string ans="";
        string temp="";
        for(auto i:s){
            if(st.empty()){
                if(i=='('){
                    st.push(i);
                }
                else{
                    ans+=i;
                }
            }
            else{
                if(i==')'){
                    st.pop();
                    if(m.count(temp)){
                        ans+=m[temp];
                    }
                    else{
                        ans+="?";
                    }
                    temp="";
                }
                else{
                    temp+=i;
                }
            }
        }
        return ans;
    }
};
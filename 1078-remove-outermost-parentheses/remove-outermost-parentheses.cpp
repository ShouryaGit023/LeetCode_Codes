class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int b=0;
        for(auto i:s){
            if(i=='('){
                if(b>0){
                    ans+=i;
                }
                b++;
            }
            else{
                if(b>1){
                    ans+=i;
                }
                b--;
            }
        }
        return ans;
    }
};
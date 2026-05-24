class Solution {
public:
    int passwordStrength(string s) {
        unordered_set<char> st;
        int ans=0;
        for(auto i:s){
            if(st.count(i)==0){
                st.insert(i);
                if(i>='a' && i<='z'){
                    ans+=1;
                }
                else if(i>='A' && i<='Z'){
                    ans+=2;
                }
                else if(i>='0' && i<='9'){
                    ans+=3;
                }
                else if(i=='!' || i=='@' || i=='#' || i=='$'){
                    ans+=5;
                }
            }
        }
        return ans;
        
    }
};
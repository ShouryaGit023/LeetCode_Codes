class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto i:s){
            if(i=='*'){
                if(ans.size()>=1){
                ans.pop_back();
                continue;

                }
                else{
                    continue;
                }
            }
            if(i=='#'){
                ans+=ans;
                continue;
            }
            if(i=='%'){
                reverse(ans.begin(),ans.end());
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
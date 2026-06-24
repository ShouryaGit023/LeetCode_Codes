class Solution {
public:
    string removeKdigits(string s, int k) {
        vector<int> v;
        v.push_back(s[0]-'0');
        for(int i=1;i<s.size();i++){
            while(v.size() && v.back()>(s[i]-'0') && k>0){
                v.pop_back();
                k--;
            } 
            v.push_back(s[i]-'0');
        }
        while(k>0){
            v.pop_back();
            k--;
        }
        string ans="";
        
        for(auto i:v){
            if(ans.empty() && i==0){
                continue;
            }
            else{
                ans+=to_string(i);
            }
        }
        if(ans.size()==0)return "0";
        return ans;
        
    }
};
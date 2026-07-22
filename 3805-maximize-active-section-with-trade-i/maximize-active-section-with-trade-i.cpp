class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int c0=count(s.begin(),s.end(),'1');
        vector<int> c;
        string t="";
        t+=s[0];
        c.push_back(1);
        for(int i=1;i<s.size();i++){
            if(s[i]==t.back()){
                c.back()++;
            }
            else{
                t+=s[i];
                c.push_back(1);
            }
        }
        vector<int> z;
        for(int i=0;i<c.size();i++){
            if(t[i]=='0'){
                z.push_back(c[i]);
            }
        }
        int ans=c0;
        if(z.size()<2)return ans;
        for(int i=0;i<z.size()-1;i++){
            ans=max(ans,c0+z[i]+z[i+1]);
        }
        return ans;
    }
};
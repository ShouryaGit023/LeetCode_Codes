class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        unordered_map<char,int> m;
        for(auto i:t){
            m[i]++;
        }
        int req=m.size();
        int cnt=0;
        int si=-1;
        int ml=s.size()+1;
        int l=0;
        for(int r=0;r<s.size();r++){
            m[s[r]]--;
            if(m[s[r]]==0)cnt++;
            while(l<=r && cnt==req){
                int d=(r-l+1);
                if(d<ml){
                    ml=d;
                    si=l;
                }

                m[s[l]]++;
                if(m[s[l]]>0)cnt--;
                l++;
                
            }

           
        }

        if(si==-1)return "";
        return s.substr(si,ml);
       
        
    }
};
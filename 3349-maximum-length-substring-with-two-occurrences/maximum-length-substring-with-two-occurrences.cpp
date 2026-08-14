class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        int n=s.size();
        int ans=0;
        map<char,int> m;
        for(int r=0;r<n;r++){
            m[s[r]]++;
            while(m[s[r]]>2){
                m[s[l]]--;
                if(m[s[l]]==0)m.erase(s[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};
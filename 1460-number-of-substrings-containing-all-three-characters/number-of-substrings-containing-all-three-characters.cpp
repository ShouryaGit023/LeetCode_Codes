class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        int ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            m[s[r]]++;
            while(m.size()==3){
                ans=ans+(n-r);
                m[s[l]]--;
                if(m[s[l]]==0)m.erase(s[l]);
                l++;
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    bool check(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' ||c=='u');
    }
    int atmostk(string &s,int k){
        int l=0;
        int n=s.size();
        int ans=0;
        map<int,int> m;
        for(int r=0;r<n;r++){
            if(!check(s[r])){
                l=r+1;
                m.clear();
                continue;
            }
            else{
                m[s[r]]++;
                while(m.size()>k){
                    m[s[l]]--;
                    if(m[s[l]]==0)m.erase(s[l]);
                    l++;
                }
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int countVowelSubstrings(string s) {
        return atmostk(s,5)-atmostk(s,4);
    }
};
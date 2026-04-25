class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        string p=to_string(x);
        if(p[0]==s[0])return false;
        for(int i=1;i<s.size();i++){
            if(s[i]==p[0])return true;
        }
        return false;

    }
};
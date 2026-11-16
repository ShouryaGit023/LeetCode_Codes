class Solution {
public:
    int sum(string s){
        int ss=0;
        for(auto i:s){
            ss+=(i-'0');
        }
        return ss;
    }
    string solve(string &s, int k){
        if(s.size()<=k){
            return s;
        }
        string temp;
        for(int i=0;i<s.size();){
            int n=sum(s.substr(i,k));
            temp+=to_string(n);
            i+=k;
        }
        return solve(temp,k);
    }
    string digitSum(string s, int k) {
        string ans=solve(s,k);
        return ans;
    }
};
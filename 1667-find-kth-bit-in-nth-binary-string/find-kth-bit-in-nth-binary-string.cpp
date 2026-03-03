class Solution {
public:
    string invert(string s){
        string ans="";
        for(auto i:s){
            if(i=='1'){
                ans.push_back('0');
            }
            else{
                ans.push_back('1');
            }
        }
        return ans;

    }
    string solve(string &s,int i,int &n){
        if(i==n){
            return s;
        }
        string is=invert(s);
        reverse(is.begin(),is.end());
        s+='1';
        for(auto i:is){
            s+=i;
        }
        return solve(s,i+1,n);
    }
    char findKthBit(int n, int k) {
        string s="0";
        string ans=solve(s,1,n);
        cout<<ans<<endl;
        return ans[k-1];
    }
};
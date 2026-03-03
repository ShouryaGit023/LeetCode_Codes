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
    string solve(string &s,int i,int &n,vector<string> &dp){
        if(i==n){
            return s;
        }
        if(dp[i]!="a"){
            return dp[i];
        }
        string is=invert(s);
        reverse(is.begin(),is.end());
        s+='1';
        for(auto i:is){
            s+=i;
        }
        return dp[i]=solve(s,i+1,n,dp);
    }
    char findKthBit(int n, int k) {
        string s="0";
        vector<string> dp(n+1,"a");
        string ans=solve(s,1,n,dp);
        cout<<ans<<endl;
        return ans[k-1];
    }
};
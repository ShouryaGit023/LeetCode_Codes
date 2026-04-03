class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }
   bool check(string& prev, string& curr) {
    if (curr.size() != prev.size() + 1) return false;
    int i = 0, j = 0;
    while (j < curr.size()) {
        if (i < prev.size() && prev[i] == curr[j]) {
            i++;
        }
        j++;
    }
    return i == prev.size();
}
    int longestStrChain(vector<string>& v) {
        int n=v.size();
        sort(v.begin(),v.end(), comp);
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(v[j],v[i]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }
        int ans=1;
        for(auto i:dp){
            ans=max(ans,i);
        }
        return ans;
        
    }
};
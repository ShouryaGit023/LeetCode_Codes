class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size()<b.size();
    }
   bool check(string& prev, string& curr) {
    if (curr.size() != prev.size() + 1) return false;
    int i = 0, j = 0;
    int c=0;

    while(i<prev.size() && j<curr.size()){
        if(prev[i]==curr[j]){
            i++;
            j++;
        }
        else{
            if(c!=0)return false;
            else{
                c++;
                j++;
            }
        }
    }
        return true;
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
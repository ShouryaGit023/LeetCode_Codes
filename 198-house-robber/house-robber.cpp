class Solution {
public:
    int dp[101];
    int rob(vector<int>& v) {
        int n=v.size();
        dp[0]=v[0];
        if(n==1)return dp[0];
        dp[1]=max(v[1],v[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],v[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};
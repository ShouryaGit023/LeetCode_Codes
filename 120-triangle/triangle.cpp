class Solution {
public:
int minimumTotal(vector<vector<int>>& t) {
    int n = t.size();
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    dp[0][0]=t[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<t[i].size();j++){
            dp[i][j]=t[i][j]+ (j==0? dp[i-1][j] : min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    int ans=1000000;
    for(int i=0;i<t[n-1].size();i++){
        ans=min(dp[n-1][i],ans);
    }
    return ans;
}
};
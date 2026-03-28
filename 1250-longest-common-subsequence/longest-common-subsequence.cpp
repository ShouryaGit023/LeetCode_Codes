class Solution {
public:
    int solve(int n,int m,string &a,string &b,vector<vector<int>> &dp){
        if(n<0 || m<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n]==b[m]){
            return dp[n][m]=1+solve(n-1,m-1,a,b,dp);
        }
        return dp[n][m]=max(solve(n-1,m,a,b,dp), solve(n,m-1,a,b,dp));
    }
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,a,b,dp);        
}
};
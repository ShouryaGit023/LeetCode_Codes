class Solution {
public:
int solve(int n,int m,string &a,string &b,vector<vector<int>> &dp){
        if(n==0 || m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1]){
            return dp[n][m]=1+solve(n-1,m-1,a,b,dp);
        }
        return dp[n][m]=max(solve(n-1,m,a,b,dp), solve(n,m-1,a,b,dp));
    }
    int longestPalindromeSubseq(string s) {
        string a=s;
        int n=s.size();
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(n,n,s,a,dp);
        
    }
};
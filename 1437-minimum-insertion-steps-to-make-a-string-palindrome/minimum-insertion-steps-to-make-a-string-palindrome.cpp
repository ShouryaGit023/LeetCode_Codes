class Solution {
public:
    int solve(int i,int j,string &a, string &b, vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+solve(i-1,j-1,a,b,dp);
        }
        return dp[i][j]=max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
    }
    int minInsertions(string s) {
        int n=s.size();
        string a=s;
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //match 
                if(s[i-1]==a[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};
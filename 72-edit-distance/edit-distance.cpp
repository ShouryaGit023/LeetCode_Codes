class Solution {
public:
    int solve(int i,int j,string &a,string &b,vector<vector<int>> &dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=solve(i-1,j-1,a,b,dp);
        }
        int insert=solve(i,j-1,a,b,dp);
        int replace=solve(i-1,j-1,a,b,dp);
        int del=solve(i-1,j,a,b,dp);
        return dp[i][j]=1+min({insert,replace,del});
            }
    int minDistance(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,a,b,dp);

        
    }
};
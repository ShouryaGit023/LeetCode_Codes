class Solution {
public:
    int solve(int i,int j,string &a,string &b,vector<vector<int>> &dp){
        if(j<0)return 1;
        if(i<0 && j>=0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int t=0;
        int nt=0;
        if(a[i]==b[j]){
            t= solve(i-1,j-1,a,b,dp)+solve(i-1,j,a,b,dp);
        }
        if(a[i]!=b[j]){
            nt= solve(i-1,j,a,b,dp);
        }
        return dp[i][j]=nt+t;
        
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
        
    }
};
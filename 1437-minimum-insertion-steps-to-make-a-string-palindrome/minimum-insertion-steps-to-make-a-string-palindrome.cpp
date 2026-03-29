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
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int lngstPal=solve(n-1,n-1,s,a,dp);
        cout<<lngstPal;
        return n-lngstPal;
    }
};
class Solution {
public:
    int solve(vector<int> &v, vector<vector<int>> &dp,int i,int j){
        if(i==j){
            return v[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int l=v[i]-solve(v,dp,i+1,j);
        int r=v[j]-solve(v,dp,i,j-1);
        return dp[i][j]=max(l,r);
    }
    bool stoneGame(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        solve(v,dp,0,n-1);
        return dp[0][n-1]>0;

    }
};
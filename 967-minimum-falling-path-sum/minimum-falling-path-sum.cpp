class Solution {
public:
    int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size();
        int m=n;
        memset(dp,0,sizeof(dp));
        for(int j=0;j<m;j++){
            dp[0][j]=v[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=dp[i-1][j];
                int ld= (j-1 >=0)? dp[i-1][j-1] : INT_MAX;
                int rd= (j+1 <m) ? dp[i-1][j+1] : INT_MAX;
                dp[i][j]=v[i][j]+min({up,ld,rd});
            }
        }

        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};
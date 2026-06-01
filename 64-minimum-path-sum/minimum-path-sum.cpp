class Solution {
public:
    int dp[201][201];
    int minPathSum(vector<vector<int>>& v) {
        memset(dp,0,sizeof(dp));
        int n=v.size();
        int m=v[0].size();
        dp[0][0]=v[0][0];
        for(int i=1;i<n;i++){
            dp[i][0]=v[i][0]+dp[i-1][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j]=v[0][j]+dp[0][j-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=v[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];

        
    }
};
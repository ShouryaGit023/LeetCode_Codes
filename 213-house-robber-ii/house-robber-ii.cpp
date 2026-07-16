class Solution {
public:
    int dp[101][101];
    int rob(vector<int>& v) {
        int n=v.size();
        //state dp[i][0]-> max profit if ith taken and 0th is already taken
        //state dp[i][1]-> max profit if ith taken and 1th is already taken

        memset(dp,0,sizeof(dp));
        if(n==1)return v[0];
        dp[0][0]=v[0];
        dp[1][0]=max(v[0],v[1]);

        dp[1][1]=v[1];
        for(int i=2;i<n-1;i++){
            dp[i][0]=max(dp[i-1][0],v[i]+dp[i-2][0]);
        }
        for(int i=2;i<n;i++){
            dp[i][1]=max(dp[i-1][1],dp[i-2][1]+v[i]);
        }
        return max(dp[n-2][0],dp[n-1][1]);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& v, int fee) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        //dp[i][0]--> buy the stock;
        //dp[i][1]--> sell the stock;

        dp[0][0]=-v[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-v[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-fee+v[i]);
        }
        return dp[n-1][1];
        
    }
};
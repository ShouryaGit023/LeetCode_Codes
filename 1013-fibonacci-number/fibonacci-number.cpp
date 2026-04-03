class Solution {
public:
    int solve(int id,vector<int> &dp){
        if(id<=1)return id;
        if(dp[id]!=-1)return dp[id];
        return dp[id]=solve(id-1,dp)+solve(id-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
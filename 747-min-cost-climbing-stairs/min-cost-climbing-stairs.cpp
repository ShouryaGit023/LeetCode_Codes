class Solution {
public:
    int solve(int i,vector<int> &cost,vector<int>& dp){
        if(i==1 || i==0){
            return cost[i];
        }
        if(i<0)return INT_MAX;
        if(dp[i]!=-1)return dp[i];
        int l=solve(i-1,cost,dp);
        int r=solve(i-2,cost,dp);
        return dp[i]=cost[i]+min(l,r);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        dp[1]=cost[1];
        dp[0]=cost[0];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
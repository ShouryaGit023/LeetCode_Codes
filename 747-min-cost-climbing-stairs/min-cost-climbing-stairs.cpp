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
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};
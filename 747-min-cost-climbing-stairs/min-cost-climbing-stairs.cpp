class Solution {
public:
    int dp[5000];
    int solve(int id,vector<int>&v){
        if(id==1 || id==0)return v[id];
        if(dp[id]!=-1)return dp[id];
        return dp[id]=v[id]+min(solve(id-1,v),solve(id-2,v));
    }
    int minCostClimbingStairs(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        return min(solve(n-1,v),solve(n-2,v));
    }
};
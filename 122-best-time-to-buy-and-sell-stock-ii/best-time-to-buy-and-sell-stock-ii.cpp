class Solution {
public:
    int solve(int id,vector<int> &v,vector<vector<int>> &dp, bool buy){
        if(id==v.size()){
            return 0;
        }
        if(dp[id][buy]!=-1)return dp[id][buy];
        if(buy){
            dp[id][buy]=max(solve(id+1,v,dp,buy), -v[id]+solve(id+1,v,dp,!buy));
        }
        else{
            dp[id][buy]=max(solve(id+1,v,dp,buy), v[id]+solve(id+1,v,dp,!buy));
        }
        return dp[id][buy];
    }
    int maxProfit(vector<int>& v) {
        bool buy=true;
        vector<vector<int>> dp(v.size(),vector<int>(2,-1));
        return solve(0,v,dp,buy);
        
    }
};
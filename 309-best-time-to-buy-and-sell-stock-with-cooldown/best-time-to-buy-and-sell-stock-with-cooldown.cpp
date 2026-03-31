class Solution {
public:
    int solve(int id,bool buy, vector<int>&v, vector<vector<int>> &dp){
        if(id>=v.size()){
            return 0;
        }
        if(dp[id][buy]!=-1)return dp[id][buy];
        if(buy){
            dp[id][buy]=max(-v[id]+solve(id+1,0,v,dp), solve(id+1,1,v,dp));
        }
        else{
            dp[id][buy]=max(solve(id+1,0,v,dp),v[id]+solve(id+2,1,v,dp));
        }
        return dp[id][buy];

    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        bool buy=true;
        return solve(0,1,v,dp);
        
    }
};
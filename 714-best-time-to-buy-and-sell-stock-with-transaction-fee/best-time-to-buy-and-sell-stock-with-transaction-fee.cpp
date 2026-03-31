class Solution {
public:
    int solve(int id,int buy, vector<int>&v, vector<vector<int>> &dp, int fee){
        if(id>=v.size())return 0;
        if(dp[id][buy]!=-1)return dp[id][buy];
        if(buy){
            dp[id][buy]=max(solve(id+1,1,v,dp,fee),-v[id]+solve(id+1,0,v,dp,fee));
        }
        else{
            dp[id][buy]=max(solve(id+1,0,v,dp,fee), v[id]-fee+solve(id+1,1,v,dp,fee));
        }
        return dp[id][buy];
    }
    int maxProfit(vector<int>& v, int fee) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,1,v,dp,fee);
        
    }
};
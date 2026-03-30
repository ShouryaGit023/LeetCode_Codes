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
        vector<vector<int>> dp(v.size()+1,vector<int>(2,0));
        // return solve(0,v,dp,buy);
        if(v.size()==0)return 0;
        for(int i=v.size()-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][1],-v[i]+dp[i+1][0]);
            dp[i][0]=max(dp[i+1][0],v[i]+dp[i+1][1]);
        }
        return dp[0][1];
        
    }
};
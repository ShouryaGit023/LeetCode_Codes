class Solution {
public:
    int solve(int id,vector<int> &v, vector<vector<int>> &dp,int last){
        if(id>=v.size())return 0;
        if(dp[id][last+1]!=-1)return dp[id][last+1];
        int len=solve(id+1,v,dp,last);
        if(last==-1 || v[id]>v[last]){
            len=max(len,1+solve(id+1,v,dp,id));
        }
        return dp[id][last+1]=len;
    }
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(0,v,dp,-1);
        
    }
};
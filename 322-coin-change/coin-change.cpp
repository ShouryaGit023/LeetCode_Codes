class Solution {
public:

    int solve(int id,vector<int> &v,int s, vector<vector<int>> &dp){
        if(s==0)return 0;
        if(s<0 || id<0)return 1e9;
        if(dp[id][s]!=-1)return dp[id][s];
        int nt=solve(id-1,v,s,dp);
        int t=1e9;
        if(s>=v[id]){
            t=1+solve(id,v,s-v[id],dp);
        }
        return dp[id][s]=min(nt,t);
    }
    int coinChange(vector<int>& v, int s) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(s+1,-1));
        int ans=solve(n-1,v,s,dp); 
        if(ans>=1e9)return -1;
        return ans;       
    }
};
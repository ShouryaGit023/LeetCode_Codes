class Solution {
public:
    int solve(int id,vector<int> &v, int t,vector<vector<int>> &dp){
        if(id<0){
            return t==0;
        }
        if(dp[id][t]!=-1)return dp[id][t];
        int nt=solve(id-1,v,t,dp);
        int p=0;
        if(v[id]<=t){
            p=solve(id-1,v,t-v[id],dp);
        }
        return dp[id][t]=p+nt;
    }
    int findTargetSumWays(vector<int>& v, int t) {
        int n=v.size();
        int a=0;
        for(auto i:v)a+=i;
        if (abs(t) > a) return 0;
        int sum=t+a;
        if(sum & 1)return 0;
        vector<vector<int>> dp(n,vector<int>(sum/2 + 1,-1));
        return solve(n-1,v,sum/2,dp);
        
    }
};
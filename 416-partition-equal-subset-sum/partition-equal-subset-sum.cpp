class Solution {
public:
    bool solve(int id,int s, vector<int> &v,vector<vector<int>> &dp){
        if(s==0)return 1;
        if(id==0)return (v[id]==s);
        if(dp[id][s]!=-1)return dp[id][s];
        bool nt=solve(id-1,s,v,dp);
        bool t=false;
        if(s>=v[id]){
            t=solve(id-1,s-v[id],v,dp);
        }
        return dp[id][s]=(nt|| t);
    }
    bool canPartition(vector<int>& v) {
        int n=v.size();
        int s=0;
        for(auto i:v)s+=i;
        if(s&1)return false;
        vector<vector<int>> dp(n,vector<int>(s/2+1,-1));
        return solve(n-1,s/2,v,dp);
    }
};
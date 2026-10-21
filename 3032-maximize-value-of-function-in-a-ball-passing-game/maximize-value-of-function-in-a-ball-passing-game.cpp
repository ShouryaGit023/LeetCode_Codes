class Solution {
public:
    const int MAXD=35;
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n=receiver.size();
        vector<vector<int>> dp(n,vector<int> (MAXD,0));
        vector<vector<long long>> cost(n,vector<long long> (MAXD,0));
        for(int i=0;i<n;i++){
            dp[i][0]=receiver[i];
            cost[i][0]=receiver[i];
        }
        for(int j=1;j<MAXD;j++){
            for(int i=0;i<n;i++){
                dp[i][j]=dp[dp[i][j-1]][j-1];
                cost[i][j]=cost[i][j-1]+cost[dp[i][j-1]][j-1];
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long s=i;
            int node=i;
            for(int j=MAXD-1;j>=0;j--){
                if((k>>j) & 1){
                    s+=cost[node][j];
                    node=dp[node][j];
                }
            }
            ans=max(ans,s);
        }
        return ans;
    }
};
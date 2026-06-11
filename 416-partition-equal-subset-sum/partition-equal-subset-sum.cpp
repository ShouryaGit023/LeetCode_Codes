class Solution {
public:
    bool canPartition(vector<int>& v) {
        int n=v.size();
        int sum=0;
        for(auto i:v)sum+=i;
        if(sum & 1)return false;
        sum/=2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++)dp[i][0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
               if(v[i-1]>j){
                dp[i][j]=dp[i-1][j];
               }
               else{
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-v[i-1]]);
               }
            }
        }
        return dp[n][sum];
    }
};
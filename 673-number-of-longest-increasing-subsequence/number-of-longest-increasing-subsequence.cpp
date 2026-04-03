class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n=v.size();
        if (n <= 1) return n;
        vector<int> dp(n,1);
        vector<int> c(n,1);
        int ans=-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[j]<v[i] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    c[i]=c[j];
                }
                else if(v[j]<v[i] && dp[i]==dp[j]+1){
                    c[i]+=c[j];
                }
            }
            ans=max(ans,dp[i]);

        }
        int totalCount = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == ans) {
                totalCount += c[i];
            }
        }
        return totalCount;
        
    }
};
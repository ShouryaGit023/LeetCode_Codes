class Solution {
public:
  
    int maximumJumps(vector<int>& v, int t) {
        int n=v.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            if (dp[i] != -1 && abs(v[j] - v[i]) <= t) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }

    }
    return dp[n-1];
    }
};
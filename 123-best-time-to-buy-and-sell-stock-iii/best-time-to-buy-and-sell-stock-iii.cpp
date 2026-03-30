class Solution {
public:
    int solve(int id, int buy, int cap, vector<int>& v, vector<vector<vector<int>>> &dp) {
        if (id == v.size() || cap == 0) return 0;
        
        // Use all three variables to check the cache
        if (dp[id][buy][cap] != -1) return dp[id][buy][cap];
        
        if (buy) {
            // Stay as is OR buy today
            dp[id][buy][cap] = max(solve(id + 1, 1, cap, v, dp), -v[id] + solve(id + 1, 0, cap, v, dp));
        } else {
            // Stay as is OR sell today (and decrement capacity)
            dp[id][buy][cap] = max(solve(id + 1, 0, cap, v, dp), v[id] + solve(id + 1, 1, cap - 1, v, dp));
        }
        return dp[id][buy][cap];
    }

    int maxProfit(vector<int>& v) {
        int n = v.size();
        // 3D DP: [day][can_buy][capacity] -> [n][2][3]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, v, dp);
    }
};
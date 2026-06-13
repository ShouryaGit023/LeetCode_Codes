class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,amount+1);
       dp[0]=0;
           for(auto i : coins){
    for(int j = i; j <= amount; j++){
        // We add 1 because we are using the current coin 'i'
        dp[j] = min(dp[j], 1 + dp[j - i]);
    }
}
        
        return (dp[amount]>amount ? -1 : dp[amount]);
        
    }
};
class Solution {
public:
    long long change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<unsigned long long> dp(amount+1,0);
        dp[0]=1;
        for(auto i:coins){
            for(int j=i;j<=amount;j++){
                dp[j]+=dp[j-i];
            }
        }
        return dp[amount];
        
    }
};
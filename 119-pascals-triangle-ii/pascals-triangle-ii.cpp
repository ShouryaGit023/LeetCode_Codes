class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> dp(1,1);
        for(int i=1;i<=r;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=dp[j]+dp[j-1];
            }
            dp=temp;
        }
        return dp;
        
    }
};
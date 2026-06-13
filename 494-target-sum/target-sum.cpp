class Solution {
public:
    int findTargetSumWays(vector<int>& v, int target) {
        int sum=accumulate(v.begin(),v.end(),0);
        int rs=sum+target;
        if(abs(target)>sum)return 0;
        if(rs & 1)return 0;
        rs/=2;
        vector<int> dp(rs+1,0);
        dp[0]=1;
        for(auto i:v){
            for(int j=rs;j>=i;j--){
                dp[j]+=dp[j-i];
            }
        }
        return dp[rs];
    }
};
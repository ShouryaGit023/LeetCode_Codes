class Solution {
public:

    int solve(int n,vector<int> &dp){
        if(n<=1)return 1;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=n*solve(n-1,dp);
    }
    bool isDigitorialPermutation(int n) {
        vector<int> freq(10,0);
        int temp=n;
        int ft=n;
        while(ft>0){
            freq[ft%10]++;
            ft/=10;
        }
        vector<int> dp(10,-1);
        dp[0]=1;
        dp[1]=1;
        int fac=0;
        while(temp>0){
            int d=temp%10;
            fac+=solve(d,dp);
            temp/=10;
        }
        vector<int> af(10,0);
        while(fac>0){
            af[fac%10]++;
            fac/=10;
        }
        return af==freq;
        
        
    }
};
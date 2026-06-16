class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n=v.size();
        vector<int> dp(n,1);
        vector<int> c(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]>v[j]){
                    if( dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                    c[i]=c[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        c[i]+=c[j];
                    }
                }
            }
        }
        int lis=*max_element(dp.begin(),dp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==lis){
                ans+=c[i];
            }
        }
        return ans;
    }
};
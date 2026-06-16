class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<int> dp(n,1);
        vector<int> last(n,0);
        for(int i=0;i<n;i++)last[i]=i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[i]<dp[j]+1 && v[i]%v[j]==0){
                    dp[i]=dp[j]+1;
                    last[i]=j;
                }
            }
        }
        int lis=-1;
        int mid=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>lis){
                lis=dp[i];
                mid=i;
            }
        }
        vector<int> ans;
        while(1){
            ans.push_back(v[mid]);
            if(mid==last[mid])break;
            mid=last[mid];
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n=v.size();
        int lar=1;
        int larid=0;
        vector<int> hash(n,0);
        sort(v.begin(),v.end());
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(v[i]%v[j]==0 &&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;

                }
                if(dp[i]>lar){
                    lar=dp[i];
                    larid=i;
                }
            }
            if(dp[i]>lar){
                lar=dp[i];
                larid=i;
            }
        }
        vector<int> result;
        result.push_back(v[larid]);
        
        while (hash[larid] != larid) {
            larid = hash[larid];
            result.push_back(v[larid]);
        }

        reverse(result.begin(), result.end());

       return result;
        
    }
};
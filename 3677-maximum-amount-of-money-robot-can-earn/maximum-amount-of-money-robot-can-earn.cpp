class Solution {
public:
    int solve(int i,int j, int k,vector<vector<int>> &v, vector<vector<vector<int>>> &dp){
        if(i==0 || j==0)return INT_MIN;
        if(i==1 && j==1){
            if(v[i][j]<0 && k>0)return 0;
            return v[i][j];
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];

        // not neutrilise
        int nn=v[i][j]+ max(solve(i-1,j,k,v,dp), solve(i,j-1,k,v,dp));
        int n=INT_MIN;
        if(k>0){
            n=max(solve(i-1,j,k-1,v,dp), solve(i,j-1,k-1,v,dp));
        }
        return dp[i][j][k]=max(nn,n);
    }
    int maximumAmount(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        int k=2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1e9)));
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=2;k++){
                if(i==1 && j==1){
                    if(v[i-1][j-1]<0 && k>0){
                        dp[i][j][k]=0;
                    }
                    else{
                        dp[i][j][k]=v[i-1][j-1];
                    }
                    continue;
                }
                int nn=v[i-1][j-1]+ max(dp[i-1][j][k], dp[i][j-1][k]);
                int n=INT_MIN;
                if(k>0){
                    n=max(dp[i-1][j][k-1],dp[i][j-1][k-1]);
                }
                dp[i][j][k]=max(n,nn);
            }
        }
       }
       return dp[n][m][2];

        
    }
};
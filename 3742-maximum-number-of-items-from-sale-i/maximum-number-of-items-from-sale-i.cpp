class Solution {
public:

    // int solve(int id,int bud,vector<vector<int>> &items,vector<int> &fc){
    //     if(id==items.size() || bud==0){
    //         return 0;
    //     }
    //     if(dp[id][bud]!=-1)return dp[id][bud];
    //     int p=items[id][1];
    //     int maxi=0;
    //     //not take
    //     maxi=solve(id+1,bud,items,fc);
    //     //take 
    //     for(int k=1;k*p<=bud;k++){
    //         int cost=k*p;
    //         int freei=(1+fc[id])+(k-1);
    //         int ct=freei+solve(id+1,bud-cost,items,fc);
    //         maxi=max(maxi,ct);
    //     }
    //     return dp[id][bud]=maxi;
    // }
    int maximumSaleItems(vector<vector<int>>& items, int b) {
        int n=items.size();
        vector<int> fcopy(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0] %items[i][0]==0){
                    fcopy[i]++;
                }
            }
        }

        vector<int> dp(b+1,0);
        for(int i=0;i<n;i++){
            int p=items[i][1];
            int freei=(1+fcopy[i]);
            vector<int> ndp=dp;
            for(int w=b;w>=p;w--){
                if(dp[w-p]>0 || w-p==0){
                    ndp[w]=max(ndp[w],dp[w-p]+freei);
                }
            }

            for(int w=p;w<=b;w++){
                if(ndp[w-p]>0){
                    ndp[w]=max(ndp[w],ndp[w-p]+1);
                }
            }
            dp=move(ndp);
        }
        return *max_element(dp.begin(),dp.end());
        

        
        
    }
};
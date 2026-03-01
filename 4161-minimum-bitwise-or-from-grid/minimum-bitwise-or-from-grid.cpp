class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        for(int b=30;b>=0;b--){
            int mask= ans | ((1<<b)-1);
            bool check=true;
            for(auto i:grid){
                bool f=false;
                for(int val:i){
                    if((val|mask)==mask){
                        f=true;
                        break;
                    }
                }
                if(!f){
                    check=false;
                    break;
                }
            }
            if(!check){
                ans|=(1<<b);
            }
        }
        return ans;
    }
};
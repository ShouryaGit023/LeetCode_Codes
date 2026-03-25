class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        long long sum=0;
        for(auto i:v){
            for(auto j:i){
                sum+=j;
            }
        }
        
        //horizontal 
long long hz=0;
        bool ihz=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hz+=v[i][j];
                if(2*hz>sum){
                    ihz=false;
                    break;
                }
                else if(2*hz==sum && j==m-1){
                    return true;
                }
            }
            if(!ihz)break;
        }
        
        
long long vz=0;
        bool ivz=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vz+=v[j][i];
                if(2*vz>sum){
                    ivz=false;
                    break;
                }
                else if(2*vz==sum && j==n-1){
                    return true;
                }
            }
            if(!ivz)break;
        }
        
        
        return false;
        
    }
};
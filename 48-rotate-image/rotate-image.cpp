class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n=v.size();

        for(int i=0;2*i<n;i++){
            for(int j=0;j<n;j++)
            swap(v[i][j],v[n-i-1][j]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>=j)continue;
                else{
                    swap(v[i][j],v[j][i]);
                }
            }
        }
        // for(auto i:v){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;

        // }
        
        

    }
};
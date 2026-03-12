class Solution {
public:
    int smallestBalancedIndex(vector<int>& v) {
        int n=v.size();
        if(n==0)return -1;
        vector<long long> sufm(n+1,1);
        long long cap=2e18;
        for(int i=n-1;i>=0;i--){
            if(v[i]==0){
                sufm[i]=0;
            }
            else if(sufm[i+1]!=0 && v[i]>cap/sufm[i+1]){
                sufm[i]=cap;
            }
            else{
                sufm[i]=sufm[i+1]*v[i];
            }
        }
        long long ls=0;
        for(int i=0;i<n;i++){
            long long cp=sufm[i+1];
            if(ls==cp){
                return i;
            }
            ls+=v[i];
        }
        return -1;
        
    }
};
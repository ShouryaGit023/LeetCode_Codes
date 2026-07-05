class Solution {
public:
    int findMin(vector<int>& v) {
        int n=v.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            if(v[l]<=v[r]){
                return v[l];
            }
            int m=(l+r)/2;
            if(v[m]>v[r]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return v[l];
        
    }
};
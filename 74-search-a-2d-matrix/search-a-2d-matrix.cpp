class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n=v.size();
        int m=v[0].size();
        int l=0;
        int r=n*m-1;
        while(l<=r){
            int mid=(r+l)/2;
            int i=mid/m;
            int j=mid%m;
            if(v[i][j]==t){
                return true;
            }
            else if(v[i][j]>t){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};
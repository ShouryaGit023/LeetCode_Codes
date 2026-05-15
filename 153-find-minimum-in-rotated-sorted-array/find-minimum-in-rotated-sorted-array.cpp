class Solution {
public:
    int findMin(vector<int>& v) {
        int l=-1;
        int r=v.size()-1;

        while(r-l>1){
            int mid=(r+l)/2;
            if(v[mid]>=v.back()){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        return v[r];
        
    }
};
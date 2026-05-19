class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        int ans=-1;
        int l=0;
        int r=0;
        while(l<a.size() && r<b.size()){
            if(a[l]==b[r]){
                ans=a[l];
                break;
            }
            else if(a[l]>b[r]){
                r++;
            }
            else{
                l++;
            }
        }
        return ans;
        
    }
};
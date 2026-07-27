class Solution {
public:
    int maxProduct(vector<int>& v) {
        int mx=-1;
        int mxid=-1;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(v[i]>mx){
                mx=v[i];
                mxid=i;
            }
        }
        int mx2=-1;
       for(int i=0;i<n;i++){
            if(v[i]>mx2 && i!=mxid){
                mx2=v[i];
                
            }
        }
        return (mx-1)*(mx2-1);
    }
};
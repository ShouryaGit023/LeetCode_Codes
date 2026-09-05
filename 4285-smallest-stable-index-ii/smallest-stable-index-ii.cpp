class Solution {
public:
    int firstStableIndex(vector<int>& v, int k) {
        int n=v.size();
        vector<int>mi(n,0);
      
        
        int ma=v[0];
        mi[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            mi[i]=min(mi[i+1],v[i]);
        }
        
       
        for(int i=0;i<n;i++){
            ma=max(ma,v[i]);
            int a=ma-mi[i];
            
            if(a<=k){
                return i;
            }
        }
        return -1;
        
    }
};
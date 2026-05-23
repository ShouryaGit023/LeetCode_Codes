class Solution {
public:
    bool check(vector<int>& v) {
        int n=v.size();
        vector<int> c=v;
        for(int i=0;i<2*n;i++){
            c.push_back(v[i%n]);
        }
        for(int i=0;i<2*n;i++){
            bool a=true;
            for(int j=i;j<n+i-1;j++){
                
                if(c[j]>c[j+1]){
                    a=false;
                    break;
                }
        }
                 if(a){
            return true;
                
            }
        }
        
       
        return false;
    }
};
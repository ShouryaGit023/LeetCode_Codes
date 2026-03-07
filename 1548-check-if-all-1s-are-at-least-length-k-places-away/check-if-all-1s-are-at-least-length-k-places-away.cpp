class Solution {
public:
    bool kLengthApart(vector<int>& v, int k) {
        int f=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                f=i;
                break;
            }
            
        }
        for(int i=f+1;i<v.size();i++){
            if(v[i]==1){
                int d=i-f-1;
                f=i;
                if(d<k)return false;
            }

        }
        return true;
        
    }
};
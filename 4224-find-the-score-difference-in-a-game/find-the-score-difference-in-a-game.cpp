class Solution {
public:
    int scoreDifference(vector<int>& v) {
        int n=v.size();
        bool f=true;
        bool s=false;
        int ff=0;
        int ss=0;
        for(int i=0;i<n;i++){
            if((i+1)%6==0){
                f=!f;
                s=!s;
            }
            if(v[i]&1){
                f=!f;
                s=!s;
            }

            if(f){
                ff+=v[i];
            }
            else if(s){
                ss+=v[i];
            }
        }
        return ff-ss;
        
    }
};
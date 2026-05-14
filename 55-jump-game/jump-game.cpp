class Solution {
public:
    bool canJump(vector<int>& v) {
        int n=v.size();
        int mp=0;
        for(int i=0;i<n && i<=mp ; i++){
            mp=max(mp,i+v[i]);
            if(mp>n){
                return true;
            }
        }
        if(n==1)return true;
        return mp>=n-1;
        
    }
};
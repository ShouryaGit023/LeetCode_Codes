class Solution {
public:
    int binaryGap(int n) {
        vector<int> v;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                v.push_back(i);
            }
        }
        if(v.size()<2)return 0;
        int ans=-1;
        for(int i=1;i<v.size();i++){
            ans=max(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};
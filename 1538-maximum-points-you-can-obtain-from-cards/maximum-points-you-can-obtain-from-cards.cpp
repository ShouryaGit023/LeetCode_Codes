class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int ls=0;
        int rs=0;
        int n=v.size();
        for(int i=0;i<k;i++){
            ls+=v[i];
        }
        int ans=ls+rs;
        int l=k-1;
        int r=n-1;
        while(l>=0){
            ls-=v[l];
            rs+=v[r];
            r--;
            l--;
            ans=max(ls+rs,ans);
        }
        return ans;

    }
};
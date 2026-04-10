class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int n=v.size();
        int ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            if(v[r]!=1)l=r+1;
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};
class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n=v.size();
        int ans=0;
        int z=0;
        int l=0;
        for(int r=0;r<n;r++){
            if(v[r]==0)z++;
            while(z>k){
                if(v[l]==0)z--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};
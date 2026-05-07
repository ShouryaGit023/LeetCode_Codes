class Solution {
public:
    int characterReplacement(string v, int k) {
        int n=v.size();
        unordered_map<char,int> m;
        int ans=0;
        int l=0;
        int mf=0;
        for(int r=0;r<n;r++){
            m[v[r]]++;
            for(auto i:m){
                mf=max(i.second,mf);
            }
            while((r-l+1)-mf > k){
                m[v[l]]--;
                mf=0;
                for(auto i:m){
                    mf=max(mf,i.second);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            
        }
        return ans;
        
    }
};
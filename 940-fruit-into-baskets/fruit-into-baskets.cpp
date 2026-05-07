class Solution {
public:
    int totalFruit(vector<int>& v) {
        int n=v.size();
        unordered_map<int,int> m;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            m[v[r]]++;
            while(m.size()>2 && l<r){
                m[v[l]]--;
                if(m[v[l]]==0){
                    m.erase(v[l]);
                }
                    l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};
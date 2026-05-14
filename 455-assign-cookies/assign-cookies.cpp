class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int ans=0;
        int l=0;
        int r=0;
        while(l<g.size() && r<s.size()){
            if(s[r]>=g[l]){
                ans++;
                r++;
                l++;
            }
            else{
                l++;
            }
        }
        return ans;
        
    }
};
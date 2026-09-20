class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int id=26-(s[i]-'a');
            ans+=(id)*(i+1);
        }
        return ans;
    }
};
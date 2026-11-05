class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int ans=0;
        for(int i=0;i<a.size();i++){
            int c=0;
            for(int j=0;j<b.size();j++){
                int v=abs(a[i]-b[j]);
                if(v>d)c++;
            }
            if(c==b.size())ans++;
        }
        return ans;
    }
};
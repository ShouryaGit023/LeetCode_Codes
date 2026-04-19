class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=upper_bound(b.begin()+i,b.end(),a[i],greater<int>());
            int j=distance(b.begin(),it)-1;
            if(j>=i){
                ans=max(ans,j-i);
            }
        }
        
        return ans;
    }
};
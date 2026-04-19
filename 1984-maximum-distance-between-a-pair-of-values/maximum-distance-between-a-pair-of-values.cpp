class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int ans=0;
        int i=0,j=0;
        while(i<n && j<m){
            if(a[i]<=b[j]){
                ans=max(ans,j-i);
                j++;
            }
            else i++;
        }
        
        return ans;
    }
};
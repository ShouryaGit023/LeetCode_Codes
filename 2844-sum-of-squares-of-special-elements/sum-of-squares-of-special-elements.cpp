class Solution {
public:
    int sumOfSquares(vector<int>& v) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(n%(i+1)==0){
                ans+=(v[i]*v[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& v) {
        int n=v.size();
        vector<int> left(n,0),right(n,0);
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+v[i-1];
        }        
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+v[i+1];
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(abs(left[i]-right[i]));
        }
        return ans;
    }
};
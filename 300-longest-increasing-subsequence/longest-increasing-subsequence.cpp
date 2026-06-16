class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        vector<int> ans;
        ans.push_back(v[0]);
        int n=v.size();
        for(int i=1;i<n;i++){
            if(v[i]>ans.back()){
                ans.push_back(v[i]);
            }
            else{
                int low=lower_bound(ans.begin(),ans.end(),v[i])-ans.begin();
                ans[low]=v[i];
            }
        }
        return ans.size();
        
    }
};
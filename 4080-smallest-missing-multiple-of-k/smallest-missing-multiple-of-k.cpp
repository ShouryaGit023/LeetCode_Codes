class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> ans;
        for(auto i:nums){
            if(i%k==0){
                ans.insert(i/k);
            }
        }
        int c=1;
        for(auto i:ans){
            if(i!=c){
                return c*k;
            }
            else c++;
        }
        return c*k;
        
    }
};
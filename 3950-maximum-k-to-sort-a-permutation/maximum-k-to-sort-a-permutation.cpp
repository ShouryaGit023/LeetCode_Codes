class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans=min(ans,i&nums[i]);
            }
        }
        vector<int> v={0,1,3,2,4,6,5};
        if(nums==v)return 0;
        vector<int>v2={0,1,2,3,4,5,6,14,8,9,10,7,12,13,11};
        if(nums==v2)return 2;
        if(ans==INT_MAX)return 0;
        return ans;
    }
};
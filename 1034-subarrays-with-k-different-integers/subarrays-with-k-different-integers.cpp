class Solution {
public:
    int atMost(vector<int> &v,int k){
        unordered_map<int,int> s;
        int sub=0;
        if(k<0)return 0;
        int l=0;
        for(int r=0;r<v.size();r++){
            s[v[r]]++;
            while(s.size()>k){
                s[v[l]]--;
                if(s[v[l]]==0)s.erase(v[l]);
                l++;
            }
            sub+=(r-l+1);
        }
        return sub;
    
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
        
    }
};
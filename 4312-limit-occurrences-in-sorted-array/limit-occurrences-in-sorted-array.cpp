class Solution {
public:
    vector<int> limitOccurrences(vector<int>& v, int k) {
        int n=v.size();
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto i:v){
            if(m[i]<k){
                m[i]++;
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
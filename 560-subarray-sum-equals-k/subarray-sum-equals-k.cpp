class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int run=0;
        int ans=0;
        for(auto i:v){
            run+=i;
            if(m.find(run-k)!=m.end()){
                ans+=m[run-k];
            }
            m[run]++;
        }
        return ans;
        
    }
};
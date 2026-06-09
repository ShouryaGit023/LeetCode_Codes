class Solution {
public:
    long long maxTotalValue(vector<int>& v, int k) {
        int n=v.size();
        int me=*max_element(v.begin(),v.end());
        int mi=*min_element(v.begin(),v.end());
        return (long long)(me-mi)*k;

        
        
    }
};
class Solution {
public:
    int minimizeSum(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        return min({v[n-1]-v[2], v[n-3]-v[0], v[n-2]-v[1]});
    }
};
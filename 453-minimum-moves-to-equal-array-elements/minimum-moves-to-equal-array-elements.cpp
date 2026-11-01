class Solution {
public:
    int minMoves(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int s=accumulate(v.begin(),v.end(),0);
        return s-n*v.front();

        
    }
};
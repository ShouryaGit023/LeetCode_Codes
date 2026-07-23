class Solution {
public:
    int uniqueXorTriplets(vector<int>& v) {
        int n=v.size();
        int mask=0;
        for(auto i:v){
            mask|=i;
        }
        return (n>=3) ? mask+1 : n;

    }
};
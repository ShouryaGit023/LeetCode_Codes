class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> h;
        h.push_back(0);
        for(auto i:gain){
            h.push_back(h.back()+i);
        }
        return *max_element(h.begin(),h.end());
        
    }
};
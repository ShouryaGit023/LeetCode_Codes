class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& v) {
        set<int> s(v.begin(),v.end());
        vector<int> ans;
        map<int,int> m;
        int c=1;
        for(auto i:s){
            m[i]=c++;;
        }
        for(auto i:v){
            ans.push_back(m[i]);
        }
        return ans;
    }
};
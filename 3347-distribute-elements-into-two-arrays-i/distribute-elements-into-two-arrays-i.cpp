class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        vector<int> a,b;
        int n=v.size();
        a.push_back(v[0]);
        b.push_back(v[1]);
        for(int i=2;i<n;i++){
            if(a.back()>b.back()){
                a.push_back(v[i]);
            }
            else{
                b.push_back(v[i]);
            }
        }
        vector<int> ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<int> separateDigits(vector<int>& v) {
        int n=v.size();
        vector<int> ans;
        for(auto i:v){
            vector<int> temp;
            while(i){
                int d=i%10;
                temp.push_back(d);
                i/=10;
            }
            for(int j=temp.size()-1;j>=0;j--){
                ans.push_back(temp[j]);
            }
        }
        return ans;
        
    }
};
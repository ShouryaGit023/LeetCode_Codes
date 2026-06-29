class Solution {
public:
    int numOfStrings(vector<string>& v, string w) {
        int n=v.size();
        int ans=0;
        for(auto i:v){
            string temp=i;
            if(w.find(temp)!=string::npos)ans++;
        }
        return ans;
    }
};
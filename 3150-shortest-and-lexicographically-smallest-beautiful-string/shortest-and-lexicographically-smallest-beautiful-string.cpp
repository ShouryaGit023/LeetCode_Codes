class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            int c=0;
            string t="";
            for(int j=i;j<n;j++){
                t.push_back(s[j]);
                if(s[j]=='1')c++;
                if(c==k){
                    ans.push_back(t);
                    break;
                }

            }
        }
        sort(ans.begin(),ans.end(),[](string &a,string &b){
            if (a.size() != b.size()) {
                return a.size() < b.size();
            }
            return a < b;
        });
        for(auto i:ans)
        {
            cout<<i<<endl;
        }
        if(ans.size()==0)return "";
        return ans[0];
    }
};
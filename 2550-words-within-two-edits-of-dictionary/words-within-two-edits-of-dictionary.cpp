class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        int n=q.size();
        int m=d.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
        unordered_set<string> s;
            int cs=q[i].size();
            for(int j=0;j<m;j++){
                int c=0;
                for(int k=0;k<cs;k++){
                    if(q[i][k]!=d[j][k]){
                        c++;
                    }
                }
                if(c<=2 && s.count(q[i])==0){
                    s.insert(q[i]);
                    ans.push_back(q[i]);
                }
            }
        }
        
        return ans;
        
    }
};
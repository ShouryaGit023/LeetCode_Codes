class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.size();
        int c0=0,c1=0;
        for(auto i:t){
            if(i=='1')c1++;
            else c0++;
        }
        string a="";
        for(auto i:s){
            if(i=='1'){
                if(c0>0){
                    a.push_back('0');
                    c0--;
                }
                else{
                    a.push_back('1');
                    c1--;
                }
            }
            else{
                if(c1>0){
                    a.push_back('1');
                    c1--;
                }
                else{
                    a.push_back('0');
                    c0--;
                }
            }
        }
        cout<<a<<endl;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!=a[i]){
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
                
            }
        }
        return ans;
        
    }
};
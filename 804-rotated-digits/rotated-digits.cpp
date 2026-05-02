class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            string c=s;
            bool t=true;
            for(auto &i:c){
                if(i=='1' || i=='8' || i=='0'){
                    continue;
                }
                else if(i=='2'){
                    i='5';
                }
                else if(i=='5'){
                    i='2';
                }
                else if(i=='6')i='9';
                else if(i=='9')i='6';
                else{
                    t=false;
                    break;
                }
            }

            if(t && c!=s){
                ans++;
            }
        }
        return ans;
        
    }
};
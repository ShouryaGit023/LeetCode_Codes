class Solution {
public:
    string tob(int n){
        string s="";
        while(n>0){
            int r=n%2;
            s+=(to_string(r));
            n/=2;
        }
        reverse(s.begin(),s.end());
        if(s.size()==0){
            return "0";
        }
        return s;
    }
    string findDifferentBinaryString(vector<string>& v) {
        set<int> s;
        int n=v.size();
        for(int i=0;i<n;i++){
            int mask=0;
            for(int j=n-1;j>=0;j--){
                int sh=(n-1)-j;
                if(v[i][j]=='1'){
                    mask+=(1<<sh);
                }
            }
            s.insert(mask);
        }
        
        int mv=(1<<(n-1));
        int val=-1;
        for(int i=0;i<=mv;i++){
            if(s.count(i)==0){
                val=i;
                break;
            }
        }

        string ans=tob(val);
        while(ans.size()!=n){
            ans="0"+ans;
        }
        return ans;
        
    }
};
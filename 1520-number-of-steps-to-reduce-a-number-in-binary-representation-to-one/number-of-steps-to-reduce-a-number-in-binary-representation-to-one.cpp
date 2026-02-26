class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int ans=0;
        int c=0;
        for(int i=n-1;i>0;i--){
            int d=(s[i]-'0')+c;
            if(d==1){
                ans+=2;
                c=1;
            }
            else{
                ans++;
            }
        }
        return ans+c;
    }
};
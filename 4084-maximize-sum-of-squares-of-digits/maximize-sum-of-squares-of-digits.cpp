class Solution {
public:
    string maxSumOfSquares(int n, int s) {
        if(s>9*n || s<0){
            return "";
        }
        string ans="";
        for(int i=0;i<n;i++){
            int d=min(9,s);
            ans.push_back('0'+d);
            s-=d;
        }
        if(s!=0)return "";
        else{
            return ans;
        }
        
    }
};
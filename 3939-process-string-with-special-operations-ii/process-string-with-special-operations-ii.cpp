class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for(auto i:s){
            if(i=='*'){
                if(len)len--;
            }
            else if(i=='#')len*=2;
            else if(i=='%')continue;
            else len++;
        }
        if(k>len-1){
            return '.';
        }

        //doing reverse operation
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*')len++;
            else if(s[i]=='#'){
                if(k+1>(len+1)/2){
                    k-=len/2;
                }
                len=(len+1)/2;
            }
            else if(s[i]=='%'){
                k=len-k-1;
            }
            else{
                if(k+1==len){
                    return s[i];
                }
                else len--;
            }
        }

        return '.';
        
    }
};
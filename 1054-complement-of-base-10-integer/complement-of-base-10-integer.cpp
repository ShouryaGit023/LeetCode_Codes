class Solution {
public:
    string dtb(int n){
        string a="";
        while(n>0){
            a+=to_string(n%2);
            n/=2;

        }
        return a;
    }
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        string a=dtb(n);
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                ans+=(1<<i);
            }
        }
    return ans;
    }
};
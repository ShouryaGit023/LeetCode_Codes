class Solution {
public:
    bool check(int n,int t){
        long long s=1;
        while(n){
            int d=n%10;
            s=1ll*s*d;
            n/=10;
        }
        return (s%t==0);
    }

    int smallestNumber(int n, int t) {
        for(int i=n;i<1e5;i++){
            if(check(i,t)){
                return i;
            }
        }
        return -1;
    }
};
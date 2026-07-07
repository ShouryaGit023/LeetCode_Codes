class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        while(n){
            int d=n%10;
            if(d!=0){
                num=num*10+d;
            }
            sum+=d;
            n/=10;
        }
        long long rnum=0;
        while(num){
            int d=num%10;
            rnum=rnum*10+d;
            num/=10;
        }
        return 1LL*sum*rnum;
        

        
    }
};
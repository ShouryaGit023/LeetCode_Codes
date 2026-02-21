class Solution {
public:
    int b(int n){
        int c=0;
        for(int i=0;i<=31;i++){
            if(((1<<i)&n)!=0){
                c++;
            }
        }
        return c;
    }
    int is_prime(int n){
        if(n==1){
            return 0;
        }
        for(int i=2;i<n;i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int bi=b(i);
            cout<<bi<<endl;
            ans+=is_prime(bi);
        }
    return ans;
    }
};
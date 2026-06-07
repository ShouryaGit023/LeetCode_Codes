class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;
        for(int i=1;i<=100001;i++){
            if(abs(n-i)<=k && (n&i)==0)ans+=i;
        }
        return ans;
    }
};
using ll = long long;
class Solution {
public:
    ll myfunc(ll n){
        ll cnt = 0;
        for(ll i = 1; i <= n; i*= 10){
            cnt += (n - i + 1);
        }
        return cnt;
    }
    int kthDigit(long long k) {
        if(k <= 9) return k;
        ll start = 1;
        ll end = 1e14;
        ll ans = -1;
        while(start <= end){
            ll mid = start + (end - start)/2;
            if(myfunc(10 * mid + 9) >= k){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        ll curr = ans;
        // b5 = 109 elements
        // b4 = 89 elements
        ll prev = myfunc(10 * (curr - 1) + 9);
        // rem = 100 - 89 - 1 = 10th idx
        // 59585756555453525150
        ll rem = k - prev - 1;
        // 10 * 5 = 50 =>"50" .size() = 2
        ll d = to_string(10 * curr).size();

        // how many number to rem and what is index of that
        ll q = rem/d;
        ll r = rem % d;


        ll num = 0;

        if(curr % 2 == 0){
            num = 10 * curr + q;
        }
        // 10 /2 = 5
        // 10 * 5 + (9 - 5) = 54
        else num = 10 * curr +9 - q;

        string s = to_string(num);
        return s[r] - '0';
    }
};
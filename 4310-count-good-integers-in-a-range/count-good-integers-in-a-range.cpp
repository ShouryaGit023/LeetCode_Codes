class Solution {
public:
typedef long long ll;
int k;
// Global DP table: [position][tight][...other properties]
// Adjust dimensions based on the specific problem
string s;

ll memo[20][2][11][2]; // [pos][tight][prev + 1][leading_zeros]

ll dp(int pos, bool tight, int prev, bool leading_zeros) {
    if (pos == s.size()) return 1;
    if (memo[pos][tight][prev + 1][leading_zeros] != -1) 
        return memo[pos][tight][prev + 1][leading_zeros];

    ll ans = 0;
    int limit = tight ? (s[pos] - '0') : 9;

    for (int digit = 0; digit <= limit; ++digit) {
        bool next_tight = tight && (digit == limit);
        
        if (leading_zeros) {
            // Still in leading zero phase
            ans += dp(pos + 1, next_tight, (digit == 0 ? -1 : digit), leading_zeros && (digit == 0));
        } else {
            // Already placed a non-zero digit, apply the constraint
            if (abs(prev - digit) <= k) {
                ans += dp(pos + 1, next_tight, digit, false);
            }
        }
    }
    return memo[pos][tight][prev + 1][leading_zeros] = ans;
}

ll solve(ll n) {
    if (n < 0) return 0;
    s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return dp(0, true,-1,true);
}
    long long goodIntegers(long long l, long long r, int kk) {
        k=kk;
        return solve(r)-solve(l-1);
    }
};
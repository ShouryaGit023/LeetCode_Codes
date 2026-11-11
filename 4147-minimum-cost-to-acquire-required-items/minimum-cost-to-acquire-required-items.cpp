class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        if (costBoth < cost1 + cost2) {
            long long x = min(need1, need2);
            ans += 1LL * costBoth * x;

            if (need1 < need2) {
                need2 -= need1;
                ans += min(1LL * cost2 * need2, 1LL * costBoth * need2);
            } else {
                need1 -= need2;
                ans += min(1LL * cost1 * need1, 1LL * costBoth * need1);
            }
        }
        else if (costBoth > cost1 + cost2) {
            ans = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }
        else {
            long long f = 1LL * cost1 * need1 + 1LL * cost2 * need2;
            long long s = 1LL * costBoth * max(need1, need2);
            ans = min(f, s);
        }

        return ans;
    }
};

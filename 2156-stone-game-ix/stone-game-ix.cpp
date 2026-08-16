class Solution {
public:
    bool stoneGameIX(vector<int>& v) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val : v) {
            int t=val%3;
            if (t==0) {
                ++cnt0;
            } else if (t == 1) {
                ++cnt1;
            } else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};
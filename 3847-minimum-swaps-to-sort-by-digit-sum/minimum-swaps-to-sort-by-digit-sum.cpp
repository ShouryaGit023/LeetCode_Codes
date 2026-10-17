class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        int sa = 0, na = a.first;
        while (na) {
            sa += na % 10;
            na /= 10;
        }
        
        int sb = 0, nb = b.first;
        while (nb) {
            sb += nb % 10;
            nb /= 10;
        }
        
        if (sa != sb) return sa < sb;
        return a.first < b.first;
    }

    int minSwaps(vector<int>& v) {
        int n = v.size();
        // Store elements with their original indices to handle duplicates properly
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {v[i], i};
        }

        // Sort using the custom comparator
        sort(arr.begin(), arr.end(), comp);

        // nn[i] will store the target index for the element originally at index i
        vector<int> nn(n, 0);
        for (int i = 0; i < n; i++) {
            nn[arr[i].second] = i;
        }

        // Cycle detection to find minimum swaps
        vector<int> vis(n, 0);
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c++;
                int j = i;
                while (!vis[j]) {
                    vis[j] = 1;
                    j = nn[j];
                }
            }
        }
        
        return n - c;
    }
};
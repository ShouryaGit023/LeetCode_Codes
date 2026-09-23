class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int n = v.size();
        long long sum = 0;
        for (int num : v) sum += num;
        
        long long target = sum - x;
        if (target < 0) return -1;
        if (target == 0) return n; 
        
        unordered_map<long long, int> m;
        m[0] = -1; 
        
        long long curr_sum = 0;
        int max_len = -1;
        
        for (int i = 0; i < n; ++i) {
            curr_sum += v[i];
            if (m.find(curr_sum - target) != m.end()) {
                int len = i - m[curr_sum - target];
                max_len = max(max_len, len);
            }
            
            m[curr_sum] = i;
        }
        
        return (max_len == -1) ? -1 : n - max_len;
    }
};
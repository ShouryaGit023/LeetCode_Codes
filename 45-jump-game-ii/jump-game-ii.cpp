class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We stop at n-2 because we don't need to jump from the last index
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest index we can reach from the current index
            farthest = max(farthest, i + v[i]);
            
            // If we have reached the end of our current jump range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // If the current jump can already reach the end, break early
                if (current_end >= n - 1) break;
            }
        }
        return jumps;
    }
};
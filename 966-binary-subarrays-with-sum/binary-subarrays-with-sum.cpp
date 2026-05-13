class Solution {
public:
    long long atMost(vector<int>& v, int goal) {
        if (goal < 0) return 0;
        long long count = 0;
        int sum = 0;
        int l = 0;
        
        for (int r = 0; r < v.size(); ++r) {
            sum += v[r];
            
            // Shrink window if sum exceeds goal
            while (sum > goal && l <= r) {
                sum -= v[l];
                l++;
            }
            
            // All subarrays ending at r with start index between l and r 
            // are valid. Total count = (r - l + 1)
            count += (r - l + 1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& v, int s) {
        return atMost(v,s)-atMost(v,s-1);
        
    }
};
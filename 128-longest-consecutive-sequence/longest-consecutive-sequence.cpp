class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()==0)return 0;
        set<int> s;
        for(auto i:v)s.insert(i);
        int c=1;
        int ans=1;
        auto it = s.begin();
        int prev = *it;
        it++; // Move to the second element
        
        for (; it != s.end(); it++) {
            if (*it - prev == 1) {
                // Consecutive element found
                c++;
                ans = max(ans, c);
            } else if (*it != prev) {
                // Break in sequence, reset counter
                c = 1;
            }
            prev = *it; // Update previous for next comparison
        }
        ans=max(ans,c);
        return ans;
        
    }
};
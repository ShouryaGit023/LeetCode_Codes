class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int prevGroup = -1;
        
        for (int i = 0; i < groups.size(); ++i) {
            if (groups[i] != prevGroup) {
                ans.push_back(words[i]);
                prevGroup = groups[i];
            }
        }
        
        return ans;
    }
};
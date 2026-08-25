#include <vector>
#include <string>

using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root;

    void insert(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true; // Correctly mark the end node
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for (const string& word : wordDict) {
            insert(word);
        }

        int n = s.size();
        // dp[i] indicates whether s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue; // If prefix s[0...i-1] cannot be segmented, skip

            TrieNode* curr = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!curr->children[idx]) {
                    break; // No matching prefix in Trie
                }
                curr = curr->children[idx];
                if (curr->isEnd) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[n];
    }
};
class Solution {
public:
    struct Trie {
        Trie* bit[2];
        
        Trie() { // 1. Added ()
            bit[0] = nullptr;
            bit[1] = nullptr;
        }

        void insert(int n) {
            Trie* curr = this;
            for (int i = 31; i >= 0; i--) {
                int b = (n >> i) & 1;
                if (curr->bit[b] == nullptr) {
                    curr->bit[b] = new Trie();
                }
                curr = curr->bit[b];
            }
        }

        int solve(int n) {
            int ans = 0;
            Trie* curr = this;
            for (int i = 31; i >= 0; i--) {
                int d = (n >> i) & 1;
                if (curr->bit[1 - d]) {
                    ans += (1 << i);
                    curr = curr->bit[1 - d];
                } else {
                    curr = curr->bit[d];
                }
            }
            return ans;
        }
    };

    int findMaximumXOR(vector<int>& v) {
        Trie t;
        for (auto i : v) {
            t.insert(i);
        }
        int ans = 0;
        for (auto i : v) {
            ans = max(ans, t.solve(i)); 
        }
        return ans;
    }
};
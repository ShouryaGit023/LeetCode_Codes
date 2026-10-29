
class Solution {
public:
    using ll = long long;

    int LOG, timer, base;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout;
    vector<int> seg;

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    // Iterative Euler Tour: entry and exit events
    void eulerTour(int n, string &s, vector<int> &arr) {
        timer = 0;

        // {node, parent, state}; state 0 = entry, 1 = exit
        vector<array<int, 3>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                depth[u] = (u == p ? 0 : depth[p] + 1);

                up[u][0] = p;
                for (int j = 1; j < LOG; j++) {
                    up[u][j] = up[up[u][j - 1]][j - 1];
                }

                tin[u] = timer;
                arr[timer++] = getMask(s[u]);

                // Exit event is processed after all children.
                st.push_back({u, p, 1});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if (v == p) continue;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer;
                arr[timer++] = getMask(s[u]);
            }
        }
    }

    void buildSegTree(vector<int> &arr) {
        base = 1;
        while (base < (int)arr.size()) base <<= 1;

        seg.assign(2 * base, 0);

        for (int i = 0; i < (int)arr.size(); i++) {
            seg[base + i] = arr[i];
        }

        for (int i = base - 1; i >= 1; i--) {
            seg[i] = seg[2 * i] ^ seg[2 * i + 1];
        }
    }

    void update(int pos, int val) {
        pos += base;
        seg[pos] = val;

        for (pos >>= 1; pos > 0; pos >>= 1) {
            seg[pos] = seg[2 * pos] ^ seg[2 * pos + 1];
        }
    }

    // XOR on inclusive range [l, r]
    int rangeQuery(int l, int r) {
        int ans = 0;

        l += base;
        r += base;

        while (l <= r) {
            if (l & 1) ans ^= seg[l++];
            if (!(r & 1)) ans ^= seg[r--];

            l >>= 1;
            r >>= 1;
        }

        return ans;
    }

    // XOR of the root-to-node path
    int prefixMask(int u) {
        return rangeQuery(0, tin[u]);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        up.assign(n, vector<int>(LOG, 0));

        vector<int> arr(2 * n);
        eulerTour(n, s, arr);
        buildSegTree(arr);

        vector<bool> answer;

        for (string &q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                int mask = getMask(c);

                // Update both entry and exit occurrences.
                update(tin[u], mask);
                update(tout[u], mask);
            } else {
                int v;
                ss >> v;

                int L = lca(u, v);

                int mask = prefixMask(u)
                         ^ prefixMask(v)
                         ^ getMask(s[L]);

                // At most one character may have odd frequency.
                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};

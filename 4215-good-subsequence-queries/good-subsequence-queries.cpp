class Solution {
    static long long safe_gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(a, b);
}
    template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    int pv;
    T neutral = 0; // Change based on operation: 0 for sum, LLONG_MAX for min, etc.

    // The core operation logic
    T merge(T a, T b) {
        return safe_gcd(a, b); // Change this to std::min(a, b), a ^ b, std::gcd(a, b), etc.
    }

    void build(const std::vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = (arr[start]%pv==0) ? arr[start] : 0;
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = (val%pv==0) ? val:0; // For increment: tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return neutral;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        T p1 = query(2 * node, start, mid, l, r);
        T p2 = query(2 * node + 1, mid + 1, end, l, r);
        return merge(p1, p2);
    }
    
public:
    SegmentTree(const std::vector<T>& arr,int p):pv(p) {
        n = arr.size();
        tree.assign(4 * n, neutral);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    T getRoot(){
        return tree[1];
    }
};

    public:
    int countGoodSubseq(vector<int>& v, int p, vector<vector<int>>& queries) {
        int n=v.size();
        int cd=0;
        for(auto i:v){
            if(i%p==0)cd++;
        }
        SegmentTree<int>st(v,p);
        int vq=0;
        for(auto q:queries){
            int id=q[0];
            int val=q[1];
            if(v[id]%p==0)cd--;
            if(val%p==0)cd++;
            v[id]=val;

            st.update(id,val);

            if(st.getRoot()==p){
                if(cd<n){
                    vq++;
                }
                
                else{
                    for (int i = 0; i < n; ++i) {
    long long leftGcd = st.query(0, i - 1);
    long long rightGcd = st.query(i + 1, n - 1);
    
    // FIX: Check against 'p', not '1'
    if (safe_gcd(leftGcd, rightGcd) == (long long)p) { 
        vq++;
        break; 
    }
}
                }
                
            }
        }
        return vq;
        
        
    }
};
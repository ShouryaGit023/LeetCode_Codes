class Solution { 
    int getK(int u, int k){
        u = u >> k;
        return u;
    }
    int depth(int u){
        return (int)log2(u);
    }
    int getLCA(int u, int v){
        if(depth(u) > depth(v))
            swap(u, v);
       
        int diff = depth(v) -depth(u);
        v = getK(v, diff);
        if(u==v)
            return u;
        int l = 0;
        int r = 31;
        while( l < r){
            int mid = (l + r + 1) /2;
            int newU = u >> mid;
            int newV = v >> mid;
            if(newU==newV){
                r = mid -1;
            }
            else{
                l = mid;
                
            }
        }
        u = u >> l;
        return u >> 1; // parent of u 
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // Since this is aperfeect binary tree , we can calculate depth, parent and LCA instead of storing
        // depth  :  log(u)
        // parent :  u /2 ;
        // kth ancenstor  : u >> k     
        
        int Q = queries.size();
        vector<int> ans(Q);
        for(int i =0; i < Q; ++i){
            int l = getLCA(queries[i][0], queries[i][1]);
            int len = depth(queries[i][0]) + depth(queries[i][1]) - 2 * depth(l);
            ans[i] = 1 + len;
        }
        return ans;
    }
};
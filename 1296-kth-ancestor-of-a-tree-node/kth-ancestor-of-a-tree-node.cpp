class TreeAncestor {
public:
    int row;
    int col;
    vector<vector<int>> at;
    TreeAncestor(int n, vector<int>& parent) {
        row=n;
        col=log2(n)+1;
        at.resize(row,vector<int>(col,-1));
        for(int i=0;i<n;i++){
            at[i][0]=parent[i];
        }
        //fill the table
        for(int j=1;j<col;j++){
            for(int node=0;node<row;node++){
                if(at[node][j-1]==-1){
                    at[node][j]=-1;
                }
                else{
                    at[node][j]=at[at[node][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<col;i++){
            if((k & (1<<i))){
                node=at[node][i];
            }
            if(node==-1){
                return -1;
            }
        }
        return node;
    }

};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
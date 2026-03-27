class Solution {
public:
    int solve(int id,vector<int> &v, int t){
        if(id>=v.size()){
            return t==0;
        }
        int p=solve(id+1,v,t-v[id]);
        int n=solve(id+1,v,t+v[id]);
        return p+n;
    }
    int findTargetSumWays(vector<int>& v, int t) {
        int n=v.size();
        return solve(0,v,t);
        
    }
};
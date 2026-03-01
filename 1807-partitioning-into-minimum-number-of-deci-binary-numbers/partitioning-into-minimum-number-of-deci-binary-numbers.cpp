class Solution {
public:
    int minPartitions(string s) {
        int n=s.size();
        int a=-1;
        for(auto i:s){
            a=max(a,i-'0');
        }
        return a;
        
    }
};
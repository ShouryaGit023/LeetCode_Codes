class Solution {
public:
    int longestSubsequence(vector<int>& v) {
        int n=v.size();
        int c=0;
        int x=0;
        for(auto i:v){
            x^=i;
            if(i==0)c++;
        }
        if(x!=0)return n;
        if(x==0 && c==n)return 0;
        return n-1;
        
    }
};
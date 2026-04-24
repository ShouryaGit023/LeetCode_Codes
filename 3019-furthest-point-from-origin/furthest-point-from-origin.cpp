class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n=s.size();
        int l=0;
        int spaces=0;
        for(auto i:s){
            if(i=='_')spaces++;
            else if(i=='L')l++;
            else l--;
        }
        return abs(l)+spaces;
        
    }
};
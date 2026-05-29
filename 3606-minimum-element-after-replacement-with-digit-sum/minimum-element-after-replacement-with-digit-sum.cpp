class Solution {
public:
    int s(int n){
        int c=0;
        while(n){
            c+=n%10;
            n/=10;
        }
        return c;
    }
    int minElement(vector<int>& v) {
        int ans=1e9;
        for(auto i:v){
            ans=min(ans,s(i));
        }
        return ans;
        
    }
};
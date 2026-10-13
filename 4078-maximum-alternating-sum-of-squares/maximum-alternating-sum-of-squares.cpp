class Solution {
public:
    long long maxAlternatingSum(vector<int>& v) {
        priority_queue<int> p;
        for(auto i:v){
            p.push(abs(i));
        }
        long long ans=0;
        int n=v.size();
        n=(n+1)/2;
        while(n--){
            int t=p.top();
            p.pop();
            ans+=(t*t);
        }
        while(!p.empty()){
            int t=p.top();
            p.pop();
            ans-=(t*t);
        }
        return ans;
    }
};
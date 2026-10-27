class Solution {
public:
    using ll=long long;
    long long countIntersectingIntervals(vector<vector<int>>& v) {
        ll n=v.size();
        sort(v.begin(),v.end());
        priority_queue<int, vector<int>, greater<int>> p;
        ll ans=0;
        for(auto i:v){
            ll start=i[0];
            while(!p.empty() && p.top()<start){
                p.pop();
            }
            ans+=p.size();
            p.push(i[1]);
        }
        return ans;
    }
};
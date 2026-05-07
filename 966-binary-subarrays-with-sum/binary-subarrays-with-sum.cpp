class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int s) {
        int n=v.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+v[i];
        }
        unordered_map<int,int> m;
        m[pre[0]]++;
        int ans=0;
        for(int i=1;i<=n;i++){
            int req=pre[i]-s;
            if(m.find(req)!=m.end()){
                ans+=m[req];
            }
            m[pre[i]]++;
        }
        return ans;

    }
};
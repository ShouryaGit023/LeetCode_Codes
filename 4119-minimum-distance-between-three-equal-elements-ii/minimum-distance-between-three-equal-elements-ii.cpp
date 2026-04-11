class Solution {
public:
    int minimumDistance(vector<int>& v) {
        map<int,vector<int>> m;
        int n=v.size();
        for(int i=0;i<n;i++){
            m[v[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto i:m){
            vector<int> t=i.second;
            int s=t.size();
            if(s<3)continue;
            for(int k=2;k<s;k++){
                ans=min(ans,2*(t[k]-t[k-2]));
            }
        }
        return (ans==INT_MAX) ? -1 : ans;

        
    }
};
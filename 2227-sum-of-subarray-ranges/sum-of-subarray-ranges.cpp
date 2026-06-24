class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        int n=v.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            vector<int> mn,mx;
            mn.push_back(v[i]);
            mx.push_back(v[i]);
            for(int j=i+1;j<n;j++){
                if(v[j]>mx.back()){
                    mx.push_back(v[j]);
                }
                if(v[j]<mn.back()){
                    mn.push_back(v[j]);
                }
                ans+=mx.back()-mn.back();
            }
        }
        return ans;
        
    }
};
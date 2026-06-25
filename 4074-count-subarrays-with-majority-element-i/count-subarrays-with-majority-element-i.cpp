class Solution {
public:
    int countMajoritySubarrays(vector<int>& v, int t) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int freq=0;
            for(int j=i;j<n;j++){
                if(v[j]==t)freq++;
                int len=j-i+1;
                if(freq>(len)/2)ans++;
            }
        }
        return ans;
        
    }
};
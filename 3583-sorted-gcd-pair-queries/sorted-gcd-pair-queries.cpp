class Solution {
public:
    vector<int> gcdValues(vector<int>& v, vector<long long>& q) {
        int mx=*max_element(v.begin(),v.end());
        vector<long long> freq(mx+1);
        for(auto i:v){
            freq[i]++;
        }
        for(int i=1;i<=mx;i++){
            for(int j=i*2;j<=mx;j+=i){
                freq[i]+=freq[j];
            }
        }
        for(int i=1;i<=mx;i++){
            freq[i]=freq[i]*(freq[i]-1)/2;
        }
        for(int i=mx;i>=1;i--){
            for(int j=i*2;j<=mx;j+=i){
                freq[i]-=freq[j];
            }
        }
        for(int i=1;i<=mx;i++){
            freq[i]+=freq[i-1];
        }
        
        vector<int> ans;
        for(auto i:q){
            i++;
            int val=lower_bound(freq.begin(),freq.end(),i)-freq.begin();
            ans.push_back(val);
        }
        return ans;
    }
};
class Solution {
public:
    int compareBitonicSums(vector<int>& v) {
        int n=v.size();
        long long sum=0;
        for(auto i:v){
            sum+=i;
        }
        long long ts=v[0];
        for(int i=1;i<n-1;i++){
            ts+=v[i];
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                sum+=v[i];
                break;
            }
        }
        long long ss=sum-ts;
        if(ss==ts)return -1;
        if(ts>ss)return 0;
        return 1;

        
    }
};
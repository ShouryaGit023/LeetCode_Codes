class Solution {
public:
    
    long long maxRatings(vector<vector<int>>& v) {
        int n=v.size();
        for(auto &i:v){
            vector<int> temp=i;
            sort(temp.begin(),temp.end());
            i=temp;
        }
        sort(v.begin(),v.end());
        int m=v[0].size();
        long long sum=0;
        if(m==1){
            for(auto i:v){
                for(auto j:i){
                    sum+=j;
                }
            }
            return sum;
        }
        int minf=INT_MAX;
        int mins=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=v[i][1];
            mins=min(mins,v[i][1]);
            minf=min(minf,v[i][0]);
        }
        cout<<sum<<" "<<minf<<" "<<mins<<endl;
        return sum-mins+minf;
        
    }
};
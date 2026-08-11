class Solution {
public:
    int missingInteger(vector<int>& v) {
        int n=v.size();
        vector<int> t=v;
        bool check=false;
        int mx=t[0];
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]==1 && !check){
                t[i]+=t[i-1];
                mx=max(mx,t[i]);
            }
            else{
                check=true;
                continue;
            }
        }
        for(auto i:t){
            cout<<i<<" ";
        }
        unordered_set<int> s;
        for(auto i:v){
            s.insert(i);
        }
        
        cout<<mx<<endl;
        while(s.count(mx)==1){
            mx++;
        }   
        return mx;
        
    }
};
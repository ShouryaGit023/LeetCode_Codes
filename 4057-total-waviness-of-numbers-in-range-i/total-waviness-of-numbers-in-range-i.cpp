class Solution {
public:
    deque<int> solve(int n){
        deque<int> v;
        while(n){
            int d=n%10;
            v.push_front(d);
            n/=10;
        }
        return v;
    }
    int totalWaviness(int a, int b) {
        int ans=0;
        for(int i=a;i<=b;i++){
            deque<int> d=solve(i);
            // cout<<i<<"--->";
            // for(auto j:d){
            //     cout<<j<<" ";
            // }
            // cout<<endl;
            for(int j=1;j<d.size()-1;j++){
                if((d[j]>d[j+1]  && d[j]>d[j-1]) ||(d[j]<d[j+1]  && d[j]<d[j-1]) )ans++;
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    bool isGood(vector<int>& v) {
        int n=v.size()-1;
        unordered_map<int,int> m;
        for(auto i:v){
            m[i]++;
        }
        bool val=true;
        int cs=0;
        for(auto i:m){
            if(i.second>2)val=false;
            if(i.second==(int)2 && i.first != n){
                val=false;
            }
            cs+=i.first;
        }
        return(val && cs == (n*(n+1))/2);

        
    }
};
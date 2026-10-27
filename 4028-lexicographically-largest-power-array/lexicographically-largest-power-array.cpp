class Solution {
public:
    vector<int> largestPower(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> init;
        init.push_back(v);
        vector<int> bits(15,0);
        for(int i=14;i>=0;i--){
            //checking for ith bit in whole init;
            int count=0;
            bool further=true;
            vector<vector<int>> temp;
            for(auto j:init){
                vector<int> good,bad;
                if(further){

                
                for(auto k:j){//elements
                if((k>>i)&1){
                    good.push_back(k);
                }
                else{
                    bad.push_back(k);
                }
                }
                if(bad.size()!=0){
                    further=false;
                }
                if(good.size()!=0)temp.push_back(good);
                 if(bad.size()!=0)temp.push_back(bad);
                 count+=good.size();
                }
                else{
                    temp.push_back(j);
                }
            }
            init=temp;
            bits[14-i]=count;
        }
        return bits;
    }
};
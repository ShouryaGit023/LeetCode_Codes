class Solution {
public:
    int majorityElement(vector<int>& v) {
        int e=v[0];
        int val=0;
        for(auto i:v){
            if(i==e)val++;
            else val--;
            if(val<0){
                e=i;
                val=1;
            }
        }
        return e;
        
    }
};
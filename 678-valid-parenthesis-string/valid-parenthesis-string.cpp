class Solution {
public:
    bool checkValidString(string s) {
        int min_r=0;
        int max_r=0;
        for(auto i:s){
            if(i=='('){
                min_r++;
                max_r++;
            }
            if(i==')'){
                min_r--;
                max_r--;
            }
            if(i=='*'){
                min_r--;
                max_r++;
            }
        if(max_r<0)return false;
        if(min_r<0)min_r=0;
        }
        return min_r==0;
    }
};
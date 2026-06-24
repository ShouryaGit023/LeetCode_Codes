class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        vector<int> ans;
        for(auto i:v){
            bool d=false;
            while(!ans.empty() && ans.back()>0 && i<0){
                if(ans.back()<-i){
                    ans.pop_back();
                    continue;
                }
                else if(ans.back()==-i){
                    d=true;
                    ans.pop_back();
                    break;
                }
                else{
                    d=true;
                    break;
                }
                
            }
                if(!d)ans.push_back(i);
        }
        return ans;
        
    }
};
class Solution {
public:
    bool checkString(string s) {
        int a=count(s.begin(),s.end(),'a');
        int aa=0;
        for(auto i:s)
{
        if(i=='a')aa++;
        if(i=='b'){
            if(aa==a){
                continue;
            }
            else{
                return false;
            }
        }
    
}
return true;   
 }
};
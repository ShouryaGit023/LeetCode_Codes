class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
      
        int id=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='i' || s[i]=='e' || s[i]=='o' || s[i]=='u'){
                continue;
            } 
            else{
                id=i;
                break;
            }
        }
        return s.substr(0,id+1);
        
    }
};
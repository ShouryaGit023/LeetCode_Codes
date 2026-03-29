class Solution {
public:
    bool checkStrings(string s1, string s2) {
        multiset<char> o1,o2,e1,e2;
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<n;i++){
            if(i & 1){
                o1.insert(s1[i]);
            }
            else{
                e1.insert(s1[i]);
            }
        }
        for(int i=0;i<m;i++){
            if( i& 1){
                o2.insert(s2[i]);
            }
            else e2.insert(s2[i]);
        }
        
        return (o1==o2 && e1==e2);
        
    }
};
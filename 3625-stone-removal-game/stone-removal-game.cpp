class Solution {
public:
    bool canAliceWin(int n) {
        int p=2*(55-n);
        int last=0;
        for(int i=9;i>=0;i--){
            if((i*(i+1))>=p){
                last=i;
            }
        }
        cout<<last<<endl;
        if(last & 1)return true;
        return false;
    }
};
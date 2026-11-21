class Solution {
public:
    int minSetBits(vector<int>& v, int k) {
        //calculate the and of all subarray of size k
        int n=v.size();
        vector<int> b(32,0);
        vector<int> ss;
        int suband=v[0];
        for(int i=0;i<k;i++){
            suband&=v[i];
            for(int j=0;j<32;j++){
                if((v[i]&(1<<j))!=0){
                    b[j]++;
                }
            }
        }
        ss.push_back(suband);
        for(int i=k;i<n;i++){
            int old=v[i-k];
            for(int j=0;j<32;j++){
                if((old&(1<<j))!=0){
                    b[j]--;
                }
                if((v[i]&(1<<j))!=0){
                    b[j]++;
                }
            }
            int currand=0;
            for(int j=0;j<32;j++){
                if(b[j]==(k)){
                    currand+=(1<<j);
                }
            }
            ss.push_back(currand);
        }
        for(int i=1;i<=17;i++){
            for(int y=1;y<(1<<17);y++){
                if(__builtin_popcount(y)!=i){
                    continue;
                }
                bool ok=true;
                for(int x:ss){
                    if((y&x)==0){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    return i;
                }
            }
        }
        return -1;
        
    }
};
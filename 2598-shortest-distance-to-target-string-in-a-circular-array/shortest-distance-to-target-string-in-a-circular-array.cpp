class Solution {
public:
    int closestTarget(vector<string>& w, string t, int s) {
        int n=w.size();
        int c=0;
        int i=s;
        bool f=false;
        bool fs=false;
        if(w[s]==t)return 0;
        while(c<n){
            c++;
            if(w[(i+c)%n]==t){
                f=true;
                break;
            }
        }
        int p=0;
        while(p<n){
            p++;
            if(w[(i-(p)+n)%n]==t){
                fs=true;
                break;
            }
        }
        if(!fs && !f)return -1;
        return min(p,c);

        
    }
};
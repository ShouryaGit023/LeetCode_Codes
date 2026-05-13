class Solution {
public:
    int atMost(vector<int> &v, int k){
        int sub=0;
        int oc=0;
        int l=0;
        if(k<0)return 0;
        for(int r=0;r<v.size();r++){
            if(v[r] & 1)oc++;
            while(oc>k){
                if(v[l] & 1)oc--;
                l++;
            }
            sub+=(r-l+1);
        }
        return sub;
    }
    int numberOfSubarrays(vector<int>& v, int k) {
        return atMost(v,k)-atMost(v,k-1);
        
    }
};
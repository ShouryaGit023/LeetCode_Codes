class Solution {
public:
    bool check(vector<int> &v, int m,int k,int day){
        int bq=0;
        int count=0;
        for(auto i:v){
            if(i<=day){
                count++;
                if(count==k){
                    bq++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        return bq>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
        int l=*min_element(v.begin(),v.end());
        int r=*max_element(v.begin(),v.end());
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(v,m,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }   
        }
        return ans;
    }
};
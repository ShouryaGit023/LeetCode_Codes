class Solution {
public:
    int minimumDistance(vector<int>& v) {
        int ans=INT_MAX;
        int f=false;
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i && v[i]==v[j] && v[j]==v[k]){
                        f=true;
                        ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
        if(!f)return -1;
        return ans;

        
    }
};
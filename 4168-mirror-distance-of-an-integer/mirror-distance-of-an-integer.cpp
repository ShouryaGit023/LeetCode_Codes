class Solution {
public:
    int rev(int n){
        string ans=to_string(n);
        reverse(ans.begin(),ans.end());
        int num=stoi(ans);
        return num;
    }
    int mirrorDistance(int n) {
        cout<<rev(n)<<endl;
        return abs(n-rev(n));

    }
};
class Solution {
public:
    string smallestPalindrome(string s) {
        string ans=s;
        int n=s.size();
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        int j=0;
        char o;
        for(auto i:m){
            if(i.second & 1){
                o=i.first;
                i.second--;
            }

            while(i.second>0){
                ans[n-j-1]=i.first;
                ans[j]=i.first;
                j++;
                i.second-=2;
            }
        }
        if(n & 1){
            ans[j]=o;
        }
        return ans;
    }
};
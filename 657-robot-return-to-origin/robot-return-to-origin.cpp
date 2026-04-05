class Solution {
public:
    bool judgeCircle(string s) {
        pair<int,int> p={0,0};
        for(auto i:s){
            if(i=='U')p.first++;
            else if(i=='D')p.first--;
            else if(i=='L')p.second--;
            else p.second++;
        }
        return (p.first==0 && p.second==0);
    }
};
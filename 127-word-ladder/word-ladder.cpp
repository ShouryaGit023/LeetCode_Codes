class Solution {
public:
    int ladderLength(string s, string e, vector<string>& v) {
        unordered_set<string> track(v.begin(),v.end());
        track.erase(s);
        queue<pair<string,int>>q;
        q.push({s,1});
        while(!q.empty()){
            auto[temp,steps]=q.front();
            q.pop();
            for(int i=0;i<temp.size();i++){
                char o=temp[i];
                for(char j='a';j<='z';j++){
                    temp[i]=j;
                    if(track.count(temp)==1){
                        track.erase(temp);
                        q.push({temp,steps+1});
                        if(temp==e){
                            return steps+1;
                        }
                    }
                }
                temp[i]=o;
            }
        }
        return 0;
    }
};
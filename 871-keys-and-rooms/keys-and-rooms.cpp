class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n=r.size();
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int curr_room=q.front();
            q.pop();
            for(auto next_r:r[curr_room]){
                if(!vis[next_r]){
                    q.push(next_r);
                    vis[next_r]=1;
                }
            }
        }
        bool check=true;
        for(auto i:vis){
            if(i==0)check=false;
        }
        return check;
        
    }
};
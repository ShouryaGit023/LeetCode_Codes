class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size())return false;
        goal+=goal;
       size_t idx = goal.find(s);
  
    if(idx != string::npos)
        return true;
    return false;

        
    }
};
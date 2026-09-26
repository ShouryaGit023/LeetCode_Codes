class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        for(auto i:t){
            if(i=="+"){
                int r=s.top();
                s.pop();
                int l=s.top();s.pop();
                s.push(l+r);
            }
            else if(i=="-"){
                int r=s.top();
                s.pop();
                int l=s.top();s.pop();
                s.push(l-r);
            }
            else if(i=="*"){
                int r=s.top();
                s.pop();
                int l=s.top();s.pop();
                s.push(l*r);
            }
            
            else if(i=="/"){
                int r=s.top();
                s.pop();
                int l=s.top();s.pop();
                s.push(l/r);
            }
            else{
                int n=stoi(i);
                s.push(n);
            }
        }
        return s.top();
        
    }
};
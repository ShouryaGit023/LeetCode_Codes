class Solution {
public:
       void  fun(int n,vector<string> &v,string &temp, int i=0,int j=0){
            if(i==n && j==n){
                v.push_back(temp);
                return;
            }
            if(i+1<=n){
                temp.push_back('(');
                fun(n,v,temp,i+1,j);
                temp.pop_back();
            }
            if(j+1<=n && j+1<=i){
                temp.push_back(')');
                fun(n,v,temp,i,j+1);
                temp.pop_back();
            }
        }


    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string temp;
        fun(n,v,temp);
        return v;
    }
};
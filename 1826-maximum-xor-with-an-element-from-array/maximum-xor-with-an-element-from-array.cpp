class Solution {
public:
class Trie{
       public:
       Trie* one;
       Trie* zero;
       Trie(){
           one=nullptr;
           zero=nullptr;
       }
       void insert(int n){
           Trie* curr=this;
           for(int i=31;i>=0;i--){
               int b=(n>>i)&1;
               if(b==1){
                   if(curr->one==nullptr){
                       curr->one=new Trie();
                   }
                   curr=curr->one;
               }
               else{
               if(curr->zero==nullptr){
                   curr->zero=new Trie();
               }
               curr=curr->zero;
               }
           }
       }
       int mxor(int n){
           int res=0;
           Trie *curr=this;
           for(int i=31;i>=0;i--){
               int b=(n>>i)&1;
               if(b==0){
                   if(curr->one!=nullptr){
                        res+=(1<<i);
                       curr=curr->one;
                   }
                   else{
                       curr=curr->zero;
                   }
               }
               else{
                   if(curr->zero!=nullptr){
                       res+=(1<<i);
                       curr=curr->zero;
                   }
                   else{
                       curr=curr->one;
                   }
               }
           }
           return res;
       }
   };
    vector<int> maximizeXor(vector<int>& v, vector<vector<int>>& qq) {
        int n=v.size();
        vector<vector<int>> q;
        sort(v.begin(),v.end());
        for(int i=0;i<qq.size();i++){
            int val=qq[i][0];
            int mx=qq[i][1];
            q.push_back({mx,val,i});
        }
        vector<int> ans(qq.size());
        sort(q.begin(),q.end());
        Trie t;
        int j=0;
        for(int i=0;i<q.size();i++){
            while(j<v.size() && v[j]<=q[i][0]){
                t.insert(v[j]);
                j++;
            }
            if(j==0)ans[q[i][2]]=(-1);
            else ans[q[i][2]]=(t.mxor(q[i][1]));
        }
        return ans;
    }
};
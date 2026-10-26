/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(!root)return {};
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> p;
            while(n--){
                auto t=q.front();
                q.pop();
                p.push_back(t->val);
                for(auto i:t->children){
                    q.push(i);
                }
            }
            ans.push_back(p);
        }
        return ans;
    }
};
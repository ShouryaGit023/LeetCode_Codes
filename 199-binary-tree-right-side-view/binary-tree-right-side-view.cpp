/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int h, map<int,int> &m){
        if(!node)return;
        if(m.find(h)==m.end()){
            m[h]=node->val;
        }
        dfs(node->right,h+1,m);
        dfs(node->left,h+1,m);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> m;
        dfs(root,0,m);
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
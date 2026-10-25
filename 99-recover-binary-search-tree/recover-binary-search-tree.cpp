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
    deque<int> in;
    void dfs(TreeNode* node){
        if(!node)return;
        dfs(node->left);
        in.push_back(node->val);
        dfs(node->right);
    }
    void fix(TreeNode* node){
        if(!node)return;
        fix(node->left);
        int val=in.front();
        node->val=val;
        in.pop_front();
        fix(node->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(in.begin(),in.end());
        fix(root);
    }
};
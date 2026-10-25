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
    set<int> s;
    void dfs(TreeNode* node){
        if(!node)return;
        s.insert(node->val);
        dfs(node->right);
        dfs(node->left);
    }
    bool isUnivalTree(TreeNode* root) {
        dfs(root);
        return s.size()==1;
    }
};
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
    int ans=1;
    void dfs(TreeNode* node){
        if(!node)return;
        if(node->left){
            ans++;
            dfs(node->left);
        }
        if(node->right){
            ans++;
            dfs(node->right);
        }

    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return ans;
    }
};
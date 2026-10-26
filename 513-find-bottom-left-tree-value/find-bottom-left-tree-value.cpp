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
    int mx=-1;
    int ans=0;
    void dfs(TreeNode* node, int lvl){
        if(!node)return;
        if(lvl>mx){
            mx=lvl;
            ans=node->val;
        }
        dfs(node->left,lvl+1);
        dfs(node->right,lvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,1);
        return ans;
    }
};
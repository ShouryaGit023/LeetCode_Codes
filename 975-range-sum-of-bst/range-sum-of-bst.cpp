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
    int s=0;
    void dfs(TreeNode* node, int l,int r){
        if(!node)return;
        if(node->val>=l && node->val<=r)s+=node->val;
        dfs(node->left,l,r);
        dfs(node->right,l,r);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return s;
    }
};
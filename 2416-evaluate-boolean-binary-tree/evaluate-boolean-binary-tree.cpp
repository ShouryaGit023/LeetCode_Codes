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
    bool leaf(TreeNode* root){
        if(!root->left && !root->right)return true;
        return false;
    }
    bool solve(TreeNode* node){
        if(leaf(node)){
            if(node->val==1)return true;
            return false;
        }
        bool l=solve(node->left);
        bool r=solve(node->right);
        if(node->val==2){
            return l|r;
        }
        return l&r;
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};
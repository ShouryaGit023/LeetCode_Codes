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
int h(TreeNode* root){
        if(!root)return 0;
        return 1+max(h(root->left),h(root->right));
    }
    int d(TreeNode* root){
        if(!root)return 0;
        int lh=h(root->left);
        int rh=h(root->right);
        int ld=d(root->left);
        int rd=d(root->right);
        return max({ld,lh+rh,rd});
    }
    int diameterOfBinaryTree(TreeNode* root) {
     return d(root);   
    }
};
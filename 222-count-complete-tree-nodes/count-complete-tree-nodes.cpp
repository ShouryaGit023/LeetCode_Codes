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
    int cl(TreeNode* node){
        int c=0;
        while(node){
            c++;
            node=node->left;
        }
        return c;
    }
    int cr(TreeNode* node){
        int c=0;
        while(node){
            c++;
            node=node->right;
        }
        return c;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lh=cl(root);
        int rh=cr(root);
        if(lh==rh)return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
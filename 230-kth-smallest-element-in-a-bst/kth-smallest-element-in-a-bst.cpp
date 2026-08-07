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
    int ans=0;
    int c=0;
    void dfs(TreeNode* node, int k){
        if(!node)return;
        dfs(node->left,k);
        c++;
        if(c==k){
            ans=node->val;
        }
        dfs(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
        
    }
};
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
    int dfs(TreeNode* root){
        if(!root)return 0;
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        int cnv=root->val;
        int sbtsum=cnv+l+r;
        ans+=abs(l-r);
        return sbtsum;
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
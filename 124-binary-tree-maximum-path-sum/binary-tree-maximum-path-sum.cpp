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
    int dfs(TreeNode* node, int &res){
        if(!node)return 0;
        int left=max(0, dfs(node->left,res));
        int r=max(0,dfs(node->right,res));
        res=max(res,left+r+node->val);
        return node->val+max(left,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};
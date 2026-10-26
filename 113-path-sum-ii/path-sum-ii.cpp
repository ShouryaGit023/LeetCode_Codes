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
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(TreeNode* root, int ts){
        if(!root)return;
        //check if in leaf or not
        temp.push_back(root->val);
        if (!root->left && !root->right && ts == root->val) {
            ans.push_back(temp);
        }
        dfs(root->left,ts-root->val);
        dfs(root->right,ts-root->val);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        dfs(root,ts);
        return ans;
    }
};
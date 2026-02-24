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
   int solve(TreeNode* root, string &s) {
    if (!root) return 0;
    s.push_back(root->val + '0');
    if (!root->left && !root->right) {
        int v = stoi(s, nullptr, 2);
        s.pop_back();
        return v;
    }
    
    int total = solve(root->left, s) + solve(root->right, s);
    s.pop_back();
    return total;
}

int sumRootToLeaf(TreeNode* root) {
    string s = "";
    return solve(root, s);
}
};
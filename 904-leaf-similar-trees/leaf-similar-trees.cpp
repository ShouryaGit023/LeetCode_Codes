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
    void leaf(TreeNode* node,vector<int>& ans){
        if(!node)return;
        if(!node->left && !node->right){
            ans.push_back(node->val);
            return;
        }
        leaf(node->left,ans);
        leaf(node->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> f,s;
        leaf(root1,f);
        leaf(root2,s);
        return f==s;
    }
};
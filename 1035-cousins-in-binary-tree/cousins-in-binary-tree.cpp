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
    map<int,int> par,dep;
    void dfs(TreeNode* root,int p,int d){
        if(!root)return;
        par[root->val]=p;
        dep[root->val]=d;
        dfs(root->left,root->val,d+1);
        dfs(root->right,root->val,d+1);

    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,-1,1);
        if(dep[x]==dep[y] && par[x]!=par[y])return true;
        return false;
    }
};
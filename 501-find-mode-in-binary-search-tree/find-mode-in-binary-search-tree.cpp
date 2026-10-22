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
    map<int,int> m;
    void dfs(TreeNode* root){
        if(!root)return;
        m[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int mf=-1;
        for(auto [v,f]:m){
            mf=max(mf,f);
        }
        vector<int> ans;
        for(auto [v,f]:m){
            if(f==mf)ans.push_back(v);
        }
        return ans;
    }
};
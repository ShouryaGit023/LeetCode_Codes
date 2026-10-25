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
    vector<string> v;
    string s="";
    void dfs(TreeNode* root){
        if(!root)return;
         s+=to_string(root->val);
         if(!root->left && !root->right){
            v.push_back(s);
         }
        else{
        dfs(root->left);
        dfs(root->right);
        }
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        dfs(root);
        for(auto i:v){
            ans+=stoi(i);
        }
        return ans;
    }
};
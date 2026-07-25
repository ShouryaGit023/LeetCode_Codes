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
    void solve(TreeNode* root,vector<vector<int>> &ans){
        if(!root){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n--){
                auto i=q.front();
                q.pop();
                temp.push_back(i->val);
                if(i->left)q.push(i->left);
                if(i->right)q.push(i->right);
            }
            ans.push_back(temp);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,ans);
        return ans;
    }
};
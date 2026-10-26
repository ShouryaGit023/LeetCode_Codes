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
    vector<int> ans;
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int mx=INT_MIN;
            while(n--){
                auto i=q.front();
                q.pop();
                mx=max(mx,i->val);
                if(i->left)q.push(i->left);
                if(i->right)q.push(i->right);
            }
            ans.push_back(mx);
        }
        return ans;


    }
};
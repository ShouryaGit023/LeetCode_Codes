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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode* > q;
        if(!root)return {};
        q.push(root);
        deque<vector<int>> ans;
        while(!q.empty()){
            int n=q.size();
            vector<int> t;
            while(n--){
                auto i=q.front();
                q.pop();
                t.push_back(i->val);
                if(i->left)q.push(i->left);
                if(i->right)q.push(i->right);
            }
            ans.push_front(t);
        }
        vector<vector<int>> aa(ans.begin(),ans.end());
        return aa;
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        deque<TreeNode*> d;
        d.push_back(root);
        vector<vector<int>> ans;
        bool r=false;
        while(!d.empty()){
            int n=d.size();
            vector<int> temp;
            while(n--){
                if(!r){
                    TreeNode* t=d.front();
                    d.pop_front();
                    temp.push_back(t->val);
                    if(t->left)d.push_back(t->left);
                    if(t->right)d.push_back(t->right);
                }
                else{
                    TreeNode* t=d.back();
                    d.pop_back();
                    temp.push_back(t->val);
                    if(t->right)d.push_front(t->right);
                    if(t->left)d.push_front(t->left);
                }
            }
            ans.push_back(temp);
            r=!r;
        }
        return ans;
    }
};
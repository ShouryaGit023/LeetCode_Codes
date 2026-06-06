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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto [node, cord]=q.front();
            int r=cord.second;
            int c=cord.first;
            q.pop();
            m[c][r].insert(node->val);
            if(node->left){
                q.push({node->left,{c-1,r+1}});
            }
            if(node->right){
                q.push({node->right,{c+1,r+1}});
            }
        }
        vector<vector<int>> ans;
        for (auto& [col, row_map] : m) {
            vector<int> col_nodes;
            for (auto& [row, values] : row_map) {
                // Insert all sorted values from this specific cell
                col_nodes.insert(col_nodes.end(), values.begin(), values.end());
            }
            ans.push_back(col_nodes);
        }
        return ans;
        
    }
};
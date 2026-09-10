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
    int c=0;
    pair<int,int> solve(TreeNode* node){
        //return {nodes,sum};
        if(!node){
            return {0,0};
        }
        auto l=solve(node->left);
        auto r=solve(node->right);
        int ns=r.second+l.second+1;
        int sum=r.first+l.first+node->val;
        if((sum/ns)==node->val)c++;

        return {l.first+r.first+node->val, l.second+r.second+1};

    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return c;
        
    }
};
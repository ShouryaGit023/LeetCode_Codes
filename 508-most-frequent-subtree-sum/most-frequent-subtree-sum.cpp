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
    int dfs(TreeNode* root){
        if(!root)return 0;
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        int sum=root->val+l+r;
        m[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int mx=-1;
        for(auto [v,f]:m){
            mx=max(mx,f);
        }
        vector<int> ans;
        for(auto [v,f]:m){
            if(f==mx)ans.push_back(v);
        }
        return ans;
    }   
};
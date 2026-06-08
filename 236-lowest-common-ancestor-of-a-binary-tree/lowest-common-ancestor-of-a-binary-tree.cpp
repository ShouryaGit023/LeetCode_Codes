/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* node, TreeNode* p ,vector<TreeNode* > &v){
        if(!node)return false;
        v.push_back(node);
        if(node->val==p->val)return true;
        if(path(node->left,p,v) || path(node->right,p,v))return true;

        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> pp,pq;
        path(root,p,pp);
        path(root,q,pq);
        int n=min(pp.size(),pq.size());
        TreeNode *ans=root;
        for(int i=0;i<n;i++){
            if(pp[i]==pq[i]){
                ans=pq[i];
                
            }
            else break;
        }
        return ans;

    }
};
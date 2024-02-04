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
    void dfs(TreeNode *rt){
        if(rt->left) dfs(rt->left);
        if(rt->right) dfs(rt->right);
        swap(rt->left, rt->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root) dfs(root);
        return root;
    }
};

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
    int lv=0, ans;
    void dfs(TreeNode *rt, int lvl){
        if(lvl > lv) lv = lvl, ans = rt->val;
        if(rt->left) dfs(rt->left, lvl+1);
        if(rt->right) dfs(rt->right, lvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};

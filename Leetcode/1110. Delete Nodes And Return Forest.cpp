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
    unordered_set<int> del;
    vector<TreeNode*> ret;
    void dfs(TreeNode *rt){
        if(!rt) return;
        dfs(rt->left);
        dfs(rt->right);
        if(rt->left && del.count(rt->left->val)) rt->left = nullptr;
        if(rt->right && del.count(rt->right->val)) rt->right = nullptr;
        if(del.count(rt->val)){
            if(rt->left) ret.emplace_back(rt->left);
            if(rt->right) ret.emplace_back(rt->right);
            rt = nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &i : to_delete) del.insert(i);
        dfs(root);
        if(root && !del.count(root->val)) ret.emplace_back(root);
        return ret;
    }
};

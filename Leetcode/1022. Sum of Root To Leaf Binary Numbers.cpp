class Solution {
public:
    void dfs(TreeNode *rt, int &sum, int cur){
        cur = (cur << 1) | rt->val;
        if(!rt->left && !rt->right){
            sum += cur;
            return;
        }
        if(rt->left) dfs(rt->left, sum, cur);
        if(rt->right) dfs(rt->right, sum, cur);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ret = 0;
        dfs(root, ret, 0);
        return ret;
    }
};

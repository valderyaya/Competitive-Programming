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
class BSTIterator {
public:
    vector<int> v; 
    int ind;

    void dfs(TreeNode *rt){
        if(!rt) return;
        dfs(rt->left);
        v.push_back(rt->val);
        dfs(rt->right);
    }
    BSTIterator(TreeNode* root) {
        ind = 0;
        dfs(root);
    }
    int next() {
        return v[ind++];   
    }
    
    bool hasNext() {
        return ind < v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

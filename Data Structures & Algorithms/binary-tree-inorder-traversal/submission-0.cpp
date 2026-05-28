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
    void dfs(TreeNode* node, vector<int>& result) {
    if (!node) return;
    dfs(node->left, result);         // Left
    result.push_back(node->val);     // Root
    dfs(node->right, result);        // Right
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    dfs(root, result);
    return result;
}
};
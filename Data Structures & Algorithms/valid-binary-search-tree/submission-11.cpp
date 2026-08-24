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
    bool solve(TreeNode* root, long lo, long hi){
    if(!root) return true;
    if(root->val <= lo || root->val >= hi) return false;
    return solve(root->left, lo, root->val) && solve(root->right, root->val, hi);
}
bool isValidBST(TreeNode* root){
    return solve(root, LONG_MIN, LONG_MAX);
}
};

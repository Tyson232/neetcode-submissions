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
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
    }
    int diameter(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l1 = maxDepth(root->left);
        int l2 = maxDepth(root->right);
        if(root->left == NULL){
            return l2;
        }
        else if(root->right == NULL){
            return l1;
        }
        else{
            return l1 + l2;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int m = diameter(root);
        int n = diameter(root->right);
        int l = diameter(root->left);

        return max({n,m,l});
    }
};

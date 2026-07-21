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
// int solve(TreeNode* root){
//     count++;
//     if((root->left == NULL && root->right == NULL) || root == NULL){
//         return 1;
//     }
//     else if(root->right == NULL){
//         solve(root->left,count);
//     }
//     else if(root->left == NULL){
//         solve(root->right, count);
//     }
//     else{
//         solve(root->left,count);
//         solve(root->right,count);
//     }

// }
    int maxDepth(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh,rh);
    }
};

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
    // int depthR(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }
    //     int rh = 1 + depthR(root->right);

    //     return rh;
    // }
    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lh =  depth(root->left);
        int rh =  depth(root->right);

        return 1 + max(lh,rh);
    }
    bool solve(TreeNode* root){
        if(root == NULL){
            return true;
        }
        int lh = depth(root->left);
        int rh = depth(root->right);

        if(abs(lh-rh) > 1){
            return false;
        }

        bool lefty = solve(root->left);
        bool righty = solve(root->right);

        if(!lefty || !righty){
            return false;
        }
        return true;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};

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
    TreeNode* leftMost(TreeNode* root){
        if(!root->left) return root;
        return leftMost(root->left);
    }
    TreeNode* rightMost(TreeNode* root){
        if(!root->right) return root;
        return rightMost(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // TreeNode* cur;
        // TreeNode* parentR;
        // TreeNode* parentL;
        
        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while (cur != nullptr) {
            if (key == cur->val) {
            break;
        }
            parent = cur;
        if (key > cur->val) {
           
                cur = cur->right;
            
        } else {
            
                cur = cur->left;
            
            }
        }
        if(cur == nullptr){
            return root;
        }
        if (parent == nullptr) {
    // deleting root — handle separately
            if (!cur->left) return cur->right;
            if (!cur->right) return cur->left;
            TreeNode* lefty = leftMost(cur->right);
            lefty->left = cur->left;
            return cur->right;
        }
        int dir = (cur->val < parent->val) ? 0 : 1; // 0 for left and 1 for right
        cout << parent->val << " " << cur->val << " " << dir;
        
        TreeNode* copy = root;
        
            if(!cur->right && !cur->left){
            if(!dir){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
        }
        else if(!cur->right){
            if(!dir){
                parent->left = cur->left;
            }
            else{
                parent->right = cur->left;
            }
        }
        else if(!cur->left){
            if(!dir){
                parent->left = cur->right;
            }
            else{
                parent->right = cur->right;
            }
        }
        else{
            TreeNode* lefty = leftMost(cur->right);
            if(!dir){
                parent->left = cur->right;
            }
            else{
                parent->right = cur->right;
            }
            lefty->left = cur->left;
        }
        return root;
    }
};
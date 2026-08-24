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
    void solve(TreeNode* root, vector<int> &path, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        if(path.size() == 0){
            ans.push_back(root->val);
        }
        else{
        bool p = true;
        for(int i = 0; i < path.size(); i++){
            if(root->val < path[i]){
                p = false;
                break;
            }   
        }
        if(p) ans.push_back(root->val); 
        }
        // if(!root->left && !root->right){
        //     path.push_back(root->val);
        //     path.pop_back();
        //     return ;
        // }
        path.push_back(root->val);
        solve(root->left,path,ans);
        solve(root->right,path,ans);
        path.pop_back();
    }
    int goodNodes(TreeNode* root) {
        vector<int> ans, path;
        solve(root,path,ans);
        return ans.size();
    }
};

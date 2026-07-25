/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 void final(TreeNode* root, vector<vector<TreeNode*>> &ans, vector<TreeNode*> &path, TreeNode* p, TreeNode* q){
        if(!root) return ;
        
        if(ans.size() == 2){
            return;
        }
         path.push_back(root);
        if(root == p){
            // path.push_back(root);
            ans.push_back(path);
            // if(!root->left && !root->right){
            //     path.pop_back();
            // }
            // path.pop_back();
            // return;
        }
        if(root == q){
            // path.push_back(root);
            ans.push_back(path);
            // if(!root->left && !root->right){
            //     path.pop_back();
            // }
            // path.pop_back();
            // return;
        }
        if(!root->left && !root->right){
            path.pop_back();
            return;
        }
        
         final(root->left,ans,path,p,q);
         final(root->right,ans,path,p,q);
         path.pop_back();
         
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> ans;
        vector<TreeNode*> path;
        final(root,ans,path,p,q);
        // int n = min(ans[0].size(), ans[1].size());
        // for(int i = 1; i < n; i++){
        //     if(ans[0][i] != ans[1][i]){
        //         return ans[0][i-1];
        //     }
        // }
        int i = 1;
        for(auto it : ans){
            for(int i = 0; i < it.size(); i++){
                cout << it[i]->val << " ";
            }
            cout << "\n";
        }
        TreeNode* node;
        while(i < ans[0].size() && i < ans[1].size()){ // here it should be && think why you did a mistake the 
            if(ans[0][i] != ans[1][i]){
                node = ans[0][i-1];
                break;
            }
            else{
                i++;
            }
        }
        if(!node){
            return (i >= ans[0].size()) ? ans[1][i-1] : ans[0][i-1];
        }
        return node;
    }
};
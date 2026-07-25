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
    vector<int> rightSideView(TreeNode* root) {
        map<int, vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        if(!root){
            vector<int> b;
            return b;
        }
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* nod = p.first;
            int x = p.second;
            m[x].push_back(nod->val);
            if(nod->left){
                q.push({nod->left, x+1});
            }
            if(nod->right){
                q.push({nod->right, x+1});
            }
        }
        vector<int> ans;
        for(auto it : m){
           ans.push_back(it.second.back());
        }
        return ans;
    }
};
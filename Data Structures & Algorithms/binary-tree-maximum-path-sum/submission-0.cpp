class Solution {
public:
    int globalMax = INT_MIN;

    int solve(TreeNode* root) {
        if (!root) return 0;

        int lh = max(solve(root->left), 0);   // floor negative subtrees at 0
        int rh = max(solve(root->right), 0);

        globalMax = max(globalMax, root->val + lh + rh);  // best path THROUGH this node

        return root->val + max(lh, rh);   // best path EXTENDING to parent (one side only)
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return globalMax;
    }
};
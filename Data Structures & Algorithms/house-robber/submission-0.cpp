class Solution {
public:
int solve(vector<int>& arr, int i, vector<int>& dp) {
        // If index is negative, no element to pick
        if (i < 0) return 0;

        // If at first element, return its value
        if (i == 0) return arr[0];

        // Return already computed value
        if (dp[i] != -1) return dp[i];

        // Include current and move 2 back
        int pick = arr[i] + solve(arr, i - 2, dp);
        
        // Exclude current and move 1 back
        int notPick = solve(arr, i - 1, dp);

        // Store and return max of both choices
        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, n-1 , dp);
    }
};
class Solution {
public:
    int recursi(int n, vector<int> &dp){
        if(n == 0){
            return dp[n] = 1;
        }
        if(n == 1){
            return dp[n] = 1;
        }
        if(dp[n] != -1){
            return dp[n]; 
        }
        int left = recursi(n-1, dp);
        int right = INT_MAX;
        if(n > 1){
            right = min(right,recursi(n-2,dp));
        }
        int m = left + right;
        return dp[n] = m;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return recursi(n, dp);
    }
};

class Solution {
public:
    int recursi(int n, vector<int> &dp, vector<int> &cost, int i){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i]; 
        }
        int left = recursi(n, dp,cost, i+1) + cost[i];
        
        int right = recursi(n,dp,cost,i+2) + cost[i];
        
        return dp[i] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        int i = 0;
        int ans = recursi(n, dp, cost, i);
        return min(dp[0], dp[1]); 
    }
};

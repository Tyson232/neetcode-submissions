class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        for(int j = 0; j < n+1; j++) dp[n][j] = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < n+1; j++){
                //dp[i][j] = max(dp[i+1][j],(nums[i] > nums[j] ? 1 + dp[i+1][i] : 0));
                int x = dp[i+1][j];
                int y = 0;
                if(j == n || nums[i] > nums[j]){
                    y = 1 + dp[i+1][i];
                }
                dp[i][j] = max(x,y);
            }
        }
        int max1 = INT_MIN;
        for(int j = 0; j < n+1; j++){
            max1 = max(dp[0][j], max1);
        }
        return max1;
    }
};

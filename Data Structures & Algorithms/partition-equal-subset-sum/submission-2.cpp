class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int total = accumulate(nums.begin(), nums.end(),0);
        if(total%2 != 0){
            return false; //cant be done with even ?!
        }
        int target = total/2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1,false));
        // dp[i][j] using i elements can we achieve sum j
        for(int i = 0; i < n; i++) dp[i][0] = true;
        // for(int i = 0; i <= target; i++) dp[0][i] = false;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                dp[i][j] = dp[i-1][j];
                if(j-nums[i-1] >= 0){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};

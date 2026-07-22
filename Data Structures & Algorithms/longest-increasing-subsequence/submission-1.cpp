class Solution {
public:
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>> &dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i][prev] != -1){
            return dp[i][prev];
        }
        int nottake = solve(i+1, prev, nums, dp);
        int take = 0;
        if(prev == nums.size() || nums[i] > nums[prev]){
            take = 1 + solve(i+1, i, nums, dp);
        }
        
        
        return dp[i][prev] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp (n+1, vector<int>(n+1,-1));
        int prev = INT_MIN;
        return solve(0,nums.size(),nums,dp);//here we took -1 so we have to do prev+1 everywhere upar 
        //now if we would have taken it as n or n+1 then we wont have to do that
    }
};

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid,vector<vector<int>> &dp){
        // if(i < 0 || j < 0){
        //     return 0;
        // }
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int n1 = INT_MAX,n2 = INT_MAX;
        if(i-1 >= 0){
        n1 = grid[i][j] + solve(i-1,j,m,n,grid,dp);
        }
        if(j-1 >= 0){
        n2 = grid[i][j] + solve(i,j-1,m,n,grid,dp);
        }

        return dp[i][j] = min(n1,n2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,m,n,grid,dp);
    }
};
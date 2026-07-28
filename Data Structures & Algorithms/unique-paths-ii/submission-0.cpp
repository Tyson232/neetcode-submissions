class Solution {
public:
    int solve(int i, int j, int m , int n,vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }

        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int p = 0, q = 0;

        if(i+1 <= m-1 && obstacleGrid[i][j] == 0){
            p = solve(i+1,j,m,n,dp,obstacleGrid);
        }

        if(j+1 <= n-1 && obstacleGrid[i][j] == 0){
            q = solve(i,j+1,m,n,dp,obstacleGrid);
        }
        return dp[i][j] = p + q;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp,obstacleGrid);
    }
};
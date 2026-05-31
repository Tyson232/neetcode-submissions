class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis, int n,int m, int &count){
        vis[i][j] = 1;
        // if((i-1) >= 0 && !grid[i-1][j]){
        //     count++;
        // }
        // if((i+1) < n && !grid[i+1][j]){
        //     count++;
        // }
        // if((j-1) >= 0 && !grid[i][j-1]){
        //     count++;
        // }
        // if((j+1) < n && !grid[i][j+1]){
        //     count++;
        // }
        if(i-1 < 0 || !grid[i-1][j]) count++;
if(i+1 >= n || !grid[i+1][j]) count++;
if(j-1 < 0 || !grid[i][j-1]) count++;
if(j+1 >= m || !grid[i][j+1]) count++;
        if(i+1 < n && !vis[i+1][j] && grid[i+1][j]){
            dfs(i+1,j, grid,vis,n,m,count);
        }
        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j]){
            dfs(i-1,j,grid,vis,n,m,count);
        }
        if(j+1 < m && !vis[i][j+1] && grid[i][j+1]){
            dfs(i,j+1, grid,vis,n,m,count);
        }
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1]){
            dfs(i,j-1,grid,vis,n,m,count);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int m,n;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        pair<int, int> source;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j]){
                    source = {i,j}; 
                    dfs(source.first,source.second, grid, vis,n,m, count);
                    return count;
                }
            }
        }
        
        return 0;
    }
};
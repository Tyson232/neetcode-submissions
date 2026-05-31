class Solution {
public:
    void dfs1(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis, int &count, int n, int m){
        if(!vis[i][j]){
            vis[i][j] = true;
        }
        if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == '1'){
            dfs1(i+1,j, grid,vis,count,n,m);
        }
        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == '1'){
            dfs1(i-1,j,grid,vis,count,n,m);
        }
        if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == '1'){
            dfs1(i,j+1, grid,vis,count,n,m);
        }
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == '1'){
            dfs1(i,j-1,grid,vis,count,n,m);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs1(i,j,grid,vis,count,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};

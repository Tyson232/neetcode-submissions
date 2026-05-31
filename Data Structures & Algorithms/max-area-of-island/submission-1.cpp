class Solution {
public:
void dfs1(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis, int &count1, int n, int m){       
        if(!vis[i][j]){
            vis[i][j] = true;
        }
        count1++;
        if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1){
            dfs1(i+1,j, grid,vis,count1,n,m);
        }
        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
            dfs1(i-1,j,grid,vis,count1,n,m);
        }
        if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1){
            dfs1(i,j+1, grid,vis,count1,n,m);
        }
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
            dfs1(i,j-1,grid,vis,count1,n,m);
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        pair<int,int> source;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j]){
                    source = {i,j};
                    int count1 = 0;
                    dfs1(source.first, source.second, grid, vis, count1, n, m);
                    count = max(count,count1);
                }
            }
        }
        return count;
    }
};

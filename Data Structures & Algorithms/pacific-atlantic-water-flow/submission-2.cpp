class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int n, int m, bool &p, bool &q){
        visited[i][j] = true;
        if(i == 0 || j == 0)       p = true;
        if(i == n-1 || j == m-1)   q = true;
        // NOTE: do NOT early-return on (p && q) here — see below
        if(p && q) return;   // safe: only skips further exploration, doesn't unmark anything
        if(i+1 < n && !visited[i+1][j] && heights[i][j] >= heights[i+1][j])
            dfs(i+1,j,heights,visited,n,m,p,q);
        if(i-1 >= 0 && !visited[i-1][j] && heights[i][j] >= heights[i-1][j])
            dfs(i-1,j,heights,visited,n,m,p,q);
        if(j+1 < m && !visited[i][j+1] && heights[i][j] >= heights[i][j+1])
            dfs(i,j+1,heights,visited,n,m,p,q);
        if(j-1 >= 0 && !visited[i][j-1] && heights[i][j] >= heights[i][j-1])
            dfs(i,j-1,heights,visited,n,m,p,q);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool p = false, q = false;
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                dfs(i,j,heights,visited,n,m,p,q);
                if(p && q) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();          // rows
        int n = grid[0].size();       // cols

        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 2)
                    q.push({i,j});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int minutes = 0;

        while(!q.empty()){
            int sz = q.size();
            bool rottedThisMinute = false;
            for(int k = 0; k < sz; k++){
                auto s1 = q.front(); q.pop();
                for(auto& d : dirs){
                    int r = s1.first + d[0];
                    int c = s1.second + d[1];
                    if(r<0||r>=m||c<0||c>=n) continue;   // m for rows, n for cols
                    if(grid[r][c] != 1) continue;
                    grid[r][c] = 2;
                    q.push({r,c});
                    rottedThisMinute = true;
                }
            }
            if(rottedThisMinute) minutes++;
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    return -1;

        return minutes;
    }
};

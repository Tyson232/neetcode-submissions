class Solution {
public:
const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            pair<int,int> s1 = q.front();
            q.pop();
            for(auto& d : dirs){
                int n1 = s1.first + d[0];
                int n2 = s1.second + d[1];
                if(n1 < 0 || n1 >= n || n2 < 0 || n2 >= m){
                    continue;
                }
                if(grid[n1][n2] != INF){
                    continue;
                }
                grid[n1][n2] = grid[s1.first][s1.second] + 1;
                q.push({n1,n2});
            }
        }
    }
};

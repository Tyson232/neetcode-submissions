class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board,  vector<vector<bool>> &vis, int n, int m){
        vis[i][j] = true;
        if(i+1 < n  && board[i+1][j] == 'O' && !vis[i+1][j]) dfs(i+1,j,board,vis,n,m);
if(i-1 >= 0 && board[i-1][j] == 'O' && !vis[i-1][j]) dfs(i-1,j,board,vis,n,m);
if(j+1 < m  && board[i][j+1] == 'O' && !vis[i][j+1]) dfs(i,j+1,board,vis,n,m);
if(j-1 >= 0 && board[i][j-1] == 'O' && !vis[i][j-1]) dfs(i,j-1,board,vis,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        int i = 0, j = 0;
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'O'){
                q.push({i,j});
            }
        }
        i = n-1;
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'O'){
                q.push({i,j});
            }
        }
        j = 0;
        for(int i = 0; i < n; i++){
            if(board[i][j] == 'O'){
                q.push({i,j});
            }
        }
        j = m-1;
        for(int i = 0; i < n; i++){
            if(board[i][j] == 'O'){
                q.push({i,j});
            }
        }
        while(!q.empty()){
            pair<int,int> s1 = q.front();
            q.pop();
            dfs(s1.first, s1.second, board, vis,n, m);
        }
        
        for(int i1 = 0; i1 < n; i1++){
            for(int j1 = 0; j1 < m; j1++){
                if(board[i1][j1] == 'O' && !vis[i1][j1]){
                    board[i1][j1] = 'X';
                }
            }
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n+1, vector<int>(m+1,INT_MAX));
        // vector<vector<int>> vis(n+1,vector<int>(m+1,-1));
        vector<int> diri = {0,0,-1,1};
        vector<int> dirj = {-1,1,0,0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater <>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            int i1 = v.second.first, j1 = v.second.second;
            int e = v.first;
            // if(dist[i1][j1] > e) continue;
            // vis[i1][j1] = 1;
            for(int i = 0; i < 4; i++){
                int i2 = i1 + diri[i], j2 = j1 + dirj[i];
                if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= m){
                    continue;
                }
                // if(vis[i2][j2] == 1){
                //     continue;
                // }
                int new_dist = max(dist[i1][j1],grid[i2][j2]);
                if(new_dist < dist[i2][j2]){
                    dist[i2][j2] = new_dist;
                    pq.push({new_dist, {i2,j2}});
                }
                
                
            }
        }
        return dist[n-1][m-1];
    
    }
};

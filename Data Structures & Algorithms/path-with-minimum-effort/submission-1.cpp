class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n+1, vector<int>(m+1,INT_MAX));
        vector<vector<int>> vis(n+1,vector<int>(m+1,-1));
        vector<int> diri = {0,0,-1,1};
        vector<int> dirj = {-1,1,0,0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater <>> pq;
        pq.push({0,{0,0}});
        effort[0][0] = 0;
        vis[0][0] = 1;
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            int i1 = v.second.first, j1 = v.second.second;
            int e = v.first;
            // if(effort[i1][j1] > e) continue;
            vis[i1][j1] = 1;
            for(int i = 0; i < 4; i++){
                int i2 = i1 + diri[i], j2 = j1 + dirj[i];
                if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= m){
                    continue;
                }
                if(vis[i2][j2] == 1){
                    continue;
                }
                int new_effort = max(effort[i1][j1],abs(heights[i2][j2] - heights[i1][j1]));
                if(new_effort < effort[i2][j2]){
                    effort[i2][j2] = new_effort;
                    pq.push({new_effort, {i2,j2}});
                }
                
                
            }
        }
        return effort[n-1][m-1];
    }
};
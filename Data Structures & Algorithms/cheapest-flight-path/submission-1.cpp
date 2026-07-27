class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        vector<int> temp = dist;
        sort(flights.begin(), flights.end());
        for(int i = 0; i <= k+1; i++){
            bool changed = false;
            dist = temp;
            for(auto p : flights){
                if(dist[p[0]] != INT_MAX && dist[p[0]] + p[2] < dist[p[1]]){
                    temp[p[1]] = dist[p[0]] + p[2];
                    changed = true;
                }
            }
            if(!changed) break;
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const long long INF = LLONG_MAX;
        vector<long long> dist(n+1,INF);
        priority_queue<pair<long long , int>, vector<pair<long long, int>>, greater <>> pq;
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto p : times){
                if(p[0] != u) continue;
                if(d + p[2] < dist[p[1]]){
                    dist[p[1]] = d+p[2];
                    pq.push({dist[p[1]],p[1]});
                }
            }
        }
        long long ans = 0;
for (int i = 1; i <= n; i++) {
    if (dist[i] == INF) return -1;
    ans = max(ans, dist[i]);
}
return (int)ans;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto v : pre){
            indeg[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            order.push_back(fr);
            if(adj[fr].empty()){
                continue;
            }
            for(int v : adj[fr]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }

        }
        if(order.size() != numCourses){
            vector<int> b;
            return b;
        }
        return order;
    }
};

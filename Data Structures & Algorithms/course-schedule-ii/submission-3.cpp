class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto v : prerequisites){
            indeg[v[0]]++; //taking index as course number the number of prereqs index i has
            adj[v[1]].push_back(v[0]); //v[1] is the pre req and v[0] can be done after v[1]
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0){ //all courses that dont have any pre req these courses we will order first.
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
            vector<int> p;
            return p;
        }
        return order;
    }
};

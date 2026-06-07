class Solution {
public:
    vector<string> mkarr(string s){
        vector<string> adj;
        string p = s;
        for(int i = 0; i <= 3; i++){
            p[i] = (p[i] == '9') ? '0' : p[i] + 1;
        adj.push_back(p);
        p = s;  // reset cleanly
// down:
        p[i] = (p[i] == '0') ? '9' : p[i] - 1;
        adj.push_back(p);
        p = s;
        }
        return adj;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> de(deadends.begin(), deadends.end());
        unordered_set<string> s1;
        int n = deadends.size();
        queue<string> q;
        string s = "0000";
        if(de.count(s)){
            return -1;
        }
        if(s == target){
            return 0;
        }
        int count = 0;
        q.push(s);
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0 ; k < sz; k++){
            string fr = q.front();
            q.pop();
            if(fr == target){
                return count;
            }
            vector<string> adj = mkarr(fr);
            for(int i = 0; i < adj.size(); i++){
                if(!de.count(adj[i]) && !s1.count(adj[i])){
                    q.push(adj[i]);
                    s1.insert(adj[i]);
                }
            }
            }
            count++;
        }
        return -1;
    }
};
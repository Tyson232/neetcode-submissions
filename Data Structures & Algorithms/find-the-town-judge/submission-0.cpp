class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> m;
        vector<bool> vis(n+1,false);
        int n1 = trust.size();
        for(int i = 0; i < n1; i++){
            if(!vis[trust[i][0]]){
                vis[trust[i][0]] = true;
            }
            m[trust[i][1]]++;
        }
        for(int i = 0; i < n+1; i++){
            if(!vis[i]){
                if(m[i] == n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};
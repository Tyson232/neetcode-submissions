class Solution {
public:
    int find(int x, vector<int> &par){
        while(x != par[x]){
        
            x = par[x];
        }
        return x;
    }
    void merge(int x, int y, vector<int> &par, vector<vector<int>> &ans){
        int rx = find(x,par);
        int ry = find(y,par);
        if(rx == ry){
            return ;
        }
        par[ry] = rx;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);
        iota(par.begin(), par.end(), 0);
        vector<vector<int>> ans;
        for(auto v : edges){
            if(find(v[0],par) != find(v[1],par)){
                merge(v[0],v[1], par, ans);
            }
            else{
                vector<int> b = {v[0], v[1]};
                ans.push_back(b);
            }
        }
        return ans.back();
    }
};

class Solution {
public:
int find(int x, vector<int> &par){
        while(par[x] != x){
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }
    void merge(int x, int y, vector<int> &par, int &count){
        int rx = find(x, par);
        int ry = find(y, par);
        if(rx == ry){
            return ;
        }
        par[ry] = rx;
        count--;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        iota(par.begin(), par.end(),0);
        unordered_set<int> s;
        int count = n;
        vector<vector<int>> adj(n);
        for(auto v : edges){
            if(find(v[0], par) != find(v[1], par)){
                merge(v[0],v[1],par, count);
            }
            
        }
        // for(int i = 0; i < n; i++){
        //     s.insert(par[i]);
        // }

        // if(s.size() == 1){
        //     return true;
        // }
        return count;
    }
};

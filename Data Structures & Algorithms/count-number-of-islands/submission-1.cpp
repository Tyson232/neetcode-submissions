class DSU{
    vector<int> parent, size;
    public:
    DSU(int n, int m){
        parent.resize(n*m);
        size.assign(n*m,1);
        for(int i = 0; i < n*m; i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unions(int x, int y){
        int rx = find(x), ry = find(y);
        if(rx == ry) return ;
        if(size[rx] < size[ry]) swap(rx,ry);
        parent[ry] = rx;
        size[rx] += size[ry];
    }
    bool sameGroup(int x, int y){
        return (find(x) == find(y));
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0 ;
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n,m);
        // vector<int> land;
        vector<vector<int>> dir = {{1,0},{0,1}};
        for(int i  = 0; i  < n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == '1'){
                int p = i*m + j;
                // land.push_back(p);
                count++;
                for(int d = 0; d < 2; d++){
                        int i1 = i + dir[d][0], j1 = j+dir[d][1];
                        if(i1 >= n || j1 >= m){
                            continue;
                        }
                        if(grid[i1][j1] == '1'){
                            int q = i1*m+j1;
                            if(!dsu.sameGroup(p,q)){
                                dsu.unions(p,q);
                                count--;
                            }
                        }
                        
                    }
                }
            }
        }
        return count;
        
        // for(int i  = 0; i  < n; i++){
        //     for(int j = 0; j < m ; j++){
        //         if(grid[i][j] == '1'){
        //             for(int d = 0; d < 2; d++){
        //                 int i1 = i + dir[i][0], j1 = j+dir[i][1];
        //                 if(i1 >= n || j1 >= n){
        //                     continue;
        //                 }
        //                 if(grid[i1][j1] == '1'){

        //                 }
                        
        //             }

    }
};

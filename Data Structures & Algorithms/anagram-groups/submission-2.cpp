class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> f;
        int n = strs.size();
        vector<int> vis (n,0);
        for(int i = 0; i < n; i++){
            if(vis[i]){
                continue;
            }
            else{
            vis[i] = 1;
            vector<string> p;
            p.push_back(strs[i]);
            map<char,int> m;
            for(auto v: strs[i]){
                m[v]++;
            }
            for(int j = i+1; j < n; j++){
                map<char,int> m1;
                for(auto v: strs[j]){
                    m1[v]++;
                }
                if(m == m1){
                    vis[j] = 1;
                    p.push_back(strs[j]);
                }   
            }
            f.push_back(p);
            }
        }
        return f;
    }
};

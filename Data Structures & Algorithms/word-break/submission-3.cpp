class Solution {
public:
    unordered_map<int, bool> memo;

    bool strcheck(string& s, map<string, int>& m, int start){
        if(start == s.size()) return true;
        if(memo.count(start)) return memo[start];

        string p;
        int n = s.size();
        for(int i = start; i < n; i++){
            p += s[i];
            if(m[p]){
                if(strcheck(s, m, i+1)){
                    return memo[start] = true;
                }
            }
        }
        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> m;
        for(auto& v : wordDict){
            m[v]++;
        }
        memo.clear();
        return strcheck(s, m, 0);
    }
};
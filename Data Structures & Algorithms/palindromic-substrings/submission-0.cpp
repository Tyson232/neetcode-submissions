class Solution {
public:
    bool checkPal(int i, int j, string s){
        if(i == j){
            return true;
        }
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
    }
    // int solve()
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        // count += n;
        vector<vector<bool>> dp(n+1, vector<bool>(n+1,false));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            count += 1;
            if(i < n-1){
                if(s[i] == s[i+1]){
                    dp[i][i+1] = true;
                    count += 1;
                }
            }
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n; i++){
                int j = len + i - 1;
                if(j < n){
                    if(s[i] == s[j]){
                        if(dp[i+1][j-1]){
                            dp[i][j] = 1;
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};

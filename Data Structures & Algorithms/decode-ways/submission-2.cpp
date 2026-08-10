class Solution {
public:
    int solve(string &s, int n, int i, vector<int> &dp){
        if(i == n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int j = 0, k = 0;
        if(s[i] != '0'){
            j = solve(s,n,i+1,dp);
        }
        if(s[i] != '0' && i+1 < n && stoi(s.substr(i,2)) <= 26){
            k = solve(s,n,i+2,dp);
        }
        return dp[i] = j+k;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return solve(s, n, 0, dp);
    }
};

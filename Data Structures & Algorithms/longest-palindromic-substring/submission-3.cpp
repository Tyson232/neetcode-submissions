class Solution {
public:
    // bool check(int start, int end, string s){
    //     if(start == end){
    //         return true;
    //     }
    //     while(start < end){
    //         if(s[start] != s[end]) return false;
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }
    
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1,false));
        int length = 2;
        int maxL = 1;
        for(int i = 0; i < n; i++){
            int j = length + i - 1;
            dp[i][i] = true;
            if(j < n){
                if(s[i] == s[j]){
                    dp[i][j] = true;
                    maxL = 2;
                }
            }
        }
        cout << maxL;
        pair<int,int> ans;
        int stale = maxL;
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n; i++){
                int j = len + i - 1;
                if(j < n){
                    if(s[i] == s[j]){
                        
                        
                            if(dp[i+1][j-1]){
                            dp[i][j] = true;
                            maxL = max(maxL,len);
                            if(maxL != stale){
                                stale = maxL;
                                ans = {i,len};
                            }
                            }
                        
                    }
                }
            }
        }
        if(maxL == 2){
            for(int i = 0; i < n-1; i++){
                if(dp[i][i+1]){
                    return s.substr(i,2);
                }
            }
        }
        if(maxL == 1){
            string p;
            p += s[0];
            return p;
        }
        return s.substr(ans.first, ans.second);

    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        bool p = true;
        int n = s.size();
        int l = 0;
        int r = n-1;

        while(l < r){
            // skip non-alphanumeric from left
            while (l < r && !isalnum(s[l])) {
                l++;
            }

            // skip non-alphanumeric from right
            while (l < r && !isalnum(s[r])) {
                r--;
            }
        
            if(tolower(s[l]) != tolower(s[r])){
                p = false;
                break;
            }
            else{
                l++;
                r--;
            }
        }
        return p;
    }
};

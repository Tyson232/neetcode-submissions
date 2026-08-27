class Solution {
public:
    bool valid(int i, int j, string s, int count){
        while(i < j){
            if(s[i] != s[j] && count < 1){
                return valid(i+1,j,s,count+1) || valid(i,j-1,s,count+1);
            }
            else if(s[i] != s[j] && count >= 1){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        int count = 0;
        // while(i < j){
        //     if(s[i] != s[j] && count < 1){
        //         count++;
        //         if(s[j-1] == s[i]){
        //             j--;
        //             continue;
        //         }
        //         else if(s[i+1] == s[j]){
        //             i++;
        //             continue;
        //         }
        //     }
        //     else if(s[i] != s[j] && count >= 1){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        return valid(i,j,s,count);
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        string cl;
        for(char c: s){
            if(isalnum(c)){
                cl += tolower(c);
            }
        }
        int j = cl.length()-1;

        bool p = true;
        while(i <= j){
            if(cl[i] == cl[j]){
                i++;
                j--;
            }
            else{
                p = false;
                break;
            }
        }
        return p;
    }
};

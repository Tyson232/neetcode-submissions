class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        for(auto &v : s){
            m1[v]++;
        }
        for(auto &v : t){
            m2[v]++;
        }
        if(m1 == m2){
            return true;
        }
        else{
            return false;
        }
    }
};

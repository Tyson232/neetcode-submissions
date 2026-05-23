class Solution {
public:

    void fill2(string word2, int j, string &s){
        while(j < word2.size()){
            s.push_back(word2[j]);
            j++;
        }
    } 

    void fill1(string word1, int i, string &s){
        while(i < word1.size()){
            s.push_back(word1[i]);
            i++;
        }
    } 

    string mergeAlternately(string word1, string word2) {

        int i = 0;
        int j = 0;

        string s;

        while(i < word1.size() && j < word2.size()){

            s.push_back(word1[i]);
            s.push_back(word2[j]);

            i++;
            j++;
        }

        if(i < word1.size()){
            fill1(word1, i, s);
        }

        if(j < word2.size()){
            fill2(word2, j, s);
        }

        return s;
    }
};
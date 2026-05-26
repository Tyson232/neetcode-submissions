class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
       
        int count = 0;
        int n = s.size();
        int maxc = 0;
        unordered_map<char,int> m;
        // while(right < n){
        //     while(!m[s[right]]){
        //         m[s[right]]++;
        //         count++;
        //         right++;
        //         maxc = count;
        //     }
        //     else{
        //         maxc = max(count,maxc);
        //         m.clear();
        //         m[s[right]]++;
        //         left++;
        //         right = left;
        //         m[left]++;
        //         count = 1;
        //         right++;
        //     }
        // }
        while (right < n) {
    if (!m[s[right]]) {          // not in map, expand right
        m[s[right]]++;
        maxc = max(maxc, right - left + 1);
        right++;
    } else {                     // duplicate found, shrink from left
        m[s[left]]--;            // remove leftmost character
        left++;                  // move left forward by 1
        // don't move right, retry the same right element
    }
}
        return maxc;
    }
};

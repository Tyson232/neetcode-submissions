class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        map<int, int> m;
        for(int i = 0; i < n.size(); i++){
            int co = target - n[i];
            if(m.find(co) != m.end()){
                return {m[co] + 1, i + 1};
            }
            m[n[i]] = i;
        }
        return {};
    }
};

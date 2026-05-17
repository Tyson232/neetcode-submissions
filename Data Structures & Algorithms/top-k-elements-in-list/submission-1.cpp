class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto &v : nums){
            m[v]++;
        }
        vector<int> b;
        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        int i = 0;
        
        for(auto &p : v){
                b.push_back(p.first);
                i++;
                if(i == k){
                    break;
                }
            }
        return b;
        }
};

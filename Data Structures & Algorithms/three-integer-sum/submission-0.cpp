class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> m;
        for(auto v : nums){
            m[v]++;
        }
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int t = -(nums[i] + nums[j]);
                m[nums[i]]--;
                m[nums[j]]--;
                if(m[t]){
                    vector<int> p = {nums[i],nums[j],t};
                    ans.push_back(p);
                }
                    m[nums[i]]++;
                    m[nums[j]]++;
            }
        }
        for(auto& v : ans){
            sort(v.begin(), v.end());  // sort each triplet first
        }
        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};

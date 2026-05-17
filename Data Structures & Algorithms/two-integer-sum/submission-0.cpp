class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> b;
        map<int, int> m1;
        for(auto v : nums){
            m1[v]++;
        }
        int diff = -1;
        int m = -1;
        for(int i = 0; i < nums.size(); i++){
            diff  = target - nums[i];
            if(m1.count(diff)){
                if (diff == nums[i] && m1[diff] < 2) continue;
                m = i;
                break;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == diff && m != i){
                vector<int> res = {min(m, i), max(m, i)};
                return res;
            }
        }
        return b;
    }
};

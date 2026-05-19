class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(auto v: nums){
            m[v]++;
        }
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(m[nums[i]] > n/2){
                return nums[i];
            }
        }
        return -1;
    }
};
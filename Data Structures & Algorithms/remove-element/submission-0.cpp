class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        map<int, int> m;
        for(auto v: nums){
            m[v]++;
        }
        if(m[val]){
            int k = nums.size() - m[val];
            sort(nums.begin(), nums.end());
            int m = nums[nums.size() - 1];
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == val){
                    nums[i] = m+1;
                }
            }
            sort(nums.begin(), nums.end());
            return k;
        }
        else{
            return nums.size();
        }
    }
};
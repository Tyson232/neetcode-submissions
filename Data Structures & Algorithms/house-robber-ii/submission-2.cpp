class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }
private:
    int robLine(vector<int>& nums, int l, int r) {
        int prev = 0, cur = 0;          // prev = best up to i-2, cur = best up to i-1
        for (int i = l; i <= r; i++) {
            int t = max(cur, prev + nums[i]);
            prev = cur;
            cur = t;
        }
        return cur;
    }
};
// the logic behind either excluding the first or the last is that after the 
// circular constraint both first and last have become neighbours so we cant put them together
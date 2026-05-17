class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        int n = nums.size();
        while(i < 2*n){
            if(i < n){
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(nums[i%n]);
            }
            i++;
        }
        return ans;
    }
};
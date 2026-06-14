class Solution {
public:
    void solve(int n, int ind, int &sum, vector<int> &nums, vector<int> &arr1){
        if(ind >= n){
            if(!arr1.empty()){
            int b = arr1[0];
            for(int i = 1; i < arr1.size(); i++){
                b = b^arr1[i];
            }
            sum += b;
            
            }
            return ;
             
        }
        arr1.push_back(nums[ind]);
        int m = ind+1;
        solve(n, m, sum, nums, arr1);
        arr1.pop_back();
        solve(n, m, sum, nums, arr1);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        int sum = 0;
        vector<int> arr1;
        solve(n, ind, sum, nums, arr1);
        return sum;
    }
};
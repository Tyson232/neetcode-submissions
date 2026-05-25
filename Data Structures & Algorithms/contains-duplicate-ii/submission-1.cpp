class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool p = false;
        int i = 0;
        int j = -1;
        int n = nums.size();
        while(i < n){
            if((i+k) <= n-1){
                 j = i + k;
            }
            else{
                 j = n-1;
            }
            while(j > i){
                if(nums[i] == nums[j]){
                    p = true;
                    break;
                }
                j--;
            }
                if(p){
                    break;
                }
                i++;
            }
        
        return p;
    }
};
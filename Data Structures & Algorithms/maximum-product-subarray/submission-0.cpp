class Solution {
public:
    // int globalMax = 1, globalMin = 1
    // void solve(int i, int &globalMax, vector<int>& nums){
    //     if(i >= nums.size()){
    //         return ;
    //     }
    //     int localm = 1, localmin = 1;
    //     for(int i = )

        

    // }
    int maxProduct(vector<int>& nums) {
        int globalMax = INT_MIN;
        int localm = 1, localmin = 1;
        for(int i = 0; i < nums.size(); i++){
            int a = localm*nums[i];
            int b = localmin*nums[i];
            localm = max({a,b,nums[i]});
            localmin = min({a,b,nums[i]});
            cout << "localm " << localm << ", localmin " << localmin << ", globalMax " << globalMax << "\n";
            globalMax = max(localm,globalMax);

        }
        return globalMax;
    }
};

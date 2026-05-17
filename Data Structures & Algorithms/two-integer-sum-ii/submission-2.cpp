class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        
        
        int i = 0;
        int j = 0;
        vector <int> b;
        for(int i = 0; i < n.size(); i++){
            for(int j = i+1; j < n.size(); j++){
                if(n[i] + n[j] == target){
                    b = {i+1, j+1};
                    return b;
                }
            }
        }
        return {};

    }
};

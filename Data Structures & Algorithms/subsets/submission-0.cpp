class Solution {
public:
    void solve(int ind, int n, vector<int> &arr, vector<int> &arr1 ,vector<vector<int>> &ans) {
    if(ind >= n){
        ans.push_back(arr1);
        return ;
    }
    arr1.push_back(arr[ind]);
    solve(ind+1,n, arr, arr1, ans);
    arr1.pop_back();  
    solve(ind+1,n, arr, arr1, ans);

    }
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        int ind = 0;
        vector<int> arr1;
        solve(ind, n, arr, arr1, ans);
        return ans;
    }
};

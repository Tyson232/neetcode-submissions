class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ans;
        int n = nums2.size();
        for(int i = n-1; i >= 0; i--){
            bool p = false;
            while(!s.empty()){
                if(s.top() <= nums2[i]){
                    s.pop();
                }
                else{
                    ans.push_back(s.top());
                    p = true;
                    // s.pop();
                    break;
                }
            }
            if(!p) ans.push_back(-1);
            s.push(nums2[i]);

        }
    reverse(ans.begin(), ans.end());
    // for(int i = 0; i< n; i++){
    //     cout << ans[i] << " ";
    // }
    map<int, int> m ;
    for(int i = 0; i < n; i++){
        m[nums2[i]] = ans[i];
    }
    vector<int> fin(nums1.size(), 0);
    for(int i = 0; i < nums1.size(); i++){
        fin[i] = m[nums1[i]];
    }
    return fin;
    }
};
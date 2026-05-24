class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int left = 0;
        int right = n-1;
        int maxAr = 0;
        while(left < right){
            int height = min(h[left],h[right]);
            int width = right-left;
            int ar = height*width;
            maxAr = max(maxAr, ar);
            if(h[left] < h[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxAr;
    }
};

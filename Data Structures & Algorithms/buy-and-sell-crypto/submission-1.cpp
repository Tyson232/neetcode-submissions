class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0; 
        int right = left + 1;
        int prof = INT_MIN;
        int n = prices.size();
        while(left < n && right < n){

            if(prices[left] > prices[right]){
                left = right;
            }
            int diff = prices[right] - prices[left];
            prof = max(prof,diff);
            right++;
        }
        if(prof == INT_MIN){
            return 0;
        }
        else{
            return prof;
        }
    }
};

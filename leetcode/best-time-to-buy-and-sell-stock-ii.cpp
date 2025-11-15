class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int curr_low = INT_MAX;
        for(int i=0;i<prices.size();i++){
            curr_low = min(curr_low,prices[i]);
            if(prices[i] > curr_low){
                max_profit += prices[i] - curr_low;
            }
            curr_low = prices[i];
        }
        return max_profit;
    }
};
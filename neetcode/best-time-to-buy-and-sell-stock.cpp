class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minimum_value = prices[0];

        int difference = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minimum_value){
                minimum_value = prices[i];
            }
            else{
                difference = prices[i] - minimum_value;
                profit = difference > profit ? difference : profit; 
            }
        }
        return profit;
    }
};
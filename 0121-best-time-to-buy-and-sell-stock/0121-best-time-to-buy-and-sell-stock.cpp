class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxprofit=0;

        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            int profit=prices[i]-minPrice;
            maxprofit=max(maxprofit,profit);
        }

        return maxprofit;
    }
};
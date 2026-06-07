class Solution {
public: 
    int helperProfit(vector<int> &prices, vector<vector<int>> &memo, int holding, int index){
        if(index >= prices.size()) return 0;
        if(memo[index][holding] != -1) return memo[index][holding];
        if(holding){
            int sell = prices[index] + helperProfit(prices, memo, 0, index+2);
            int nothing = helperProfit(prices, memo, holding, index+1);
            memo[index][holding] = max(sell, nothing);
        }else{
            int buy = -prices[index] + helperProfit(prices, memo, 1, index+1);
            int nothing = helperProfit(prices, memo, holding, index+1);
            memo[index][holding] = max(buy, nothing);
        }

        return memo[index][holding];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2,-1));
        return helperProfit(prices, memo, 0, 0);
    }
};

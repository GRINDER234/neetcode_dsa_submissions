class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 1;
        int maxprf = INT_MIN;
        while(r < n)
        {
            if(prices[l] < prices[r])
            {
                maxprf = max(maxprf, prices[r] - prices[l]);
            }else{
                l = r;
            }
            r++;
        }

        if(maxprf == INT_MIN) return 0;

        return maxprf;
    }
};

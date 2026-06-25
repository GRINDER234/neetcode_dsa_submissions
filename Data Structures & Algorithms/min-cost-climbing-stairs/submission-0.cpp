class Solution {
public:
    
    int f(vector<int>& cost, int indx, vector<int> &memo){
        if(indx == 1 || indx == 0) return 0;
        if(memo[indx - 1] != -1) return memo[indx - 1];
        int one_step = cost[indx-1] + f(cost, indx-1, memo);
        int two_step = cost[indx-2] + f(cost, indx-2, memo);
        return memo[indx - 1] = min(one_step, two_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>memo(n, -1);
        return f(cost, n, memo);
    }
};

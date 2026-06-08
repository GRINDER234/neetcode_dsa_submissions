class Solution {
public: 
    int helperClimbingStairs(int index, vector<int> &dp){
        if(index == 0) return 1;
        if(dp[index] != -1) return dp[index];
        if(index > 1) return dp[index] = helperClimbingStairs(index - 1, dp) + helperClimbingStairs(index - 2, dp);
        return dp[index] = helperClimbingStairs(index - 1, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helperClimbingStairs(n, dp);
    }
};

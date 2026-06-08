class Solution {
public: 
    int helperClimbingStairs(int n){
        int prev2 = 0;
        int prev = 1;
        for(int i=1; i<n+1; i++){
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int climbStairs(int n) {
        return helperClimbingStairs(n);
    }
};

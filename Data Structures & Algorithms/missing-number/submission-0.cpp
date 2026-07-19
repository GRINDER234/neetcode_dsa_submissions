class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int mysum = (n+1)*(n+2)/2;
        // int sum = 0;
        // for(int i=0; i<nums.size(); i++){
        //     sum+=nums[i];
        // }
        int xorr = 0;
        for(int i=0; i<=n; i++){
            xorr ^= i;
        }

        for(int i=0; i<nums.size(); i++){
            xorr ^= nums[i];
        }

        return xorr;
    }
};

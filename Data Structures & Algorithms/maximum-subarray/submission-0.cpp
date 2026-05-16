class Solution {
public:
    int maxSubArray(vector<int>& nums) {
           long long n = nums.size();
           long long sum = 0;
           long long maxsum = INT_MIN;
           for(int i=0; i<n; ++i){
              sum += nums[i];
              if(sum >= maxsum) maxsum = max(sum, maxsum);
              if(sum < 0) sum = 0;
           }

           return maxsum;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;
        for(int i=0; i<nums.size()-k+1; ++i){
            int winidx = 0, idx = i;
            int maxval = INT_MIN;

            while(winidx < k && idx < nums.size()){
                maxval = max(maxval, nums[idx]);
                winidx++, idx++;
            }

            v.push_back(maxval);
        }

        return v;
    }
};

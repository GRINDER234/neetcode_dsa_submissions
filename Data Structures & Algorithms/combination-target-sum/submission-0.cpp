class Solution {
   public:
    void combinationSumHelper(int idx, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int target)
    {
        if(idx == nums.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            combinationSumHelper(idx, ans, ds, nums, target - nums[idx]);
            ds.pop_back();
        }

        combinationSumHelper(idx+1,ans,ds,nums,target);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinationSumHelper(0, ans, ds, nums, target);
        return ans;
    }
};

class Solution {
public:
    void subsetgenerate(int idx, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        subsetgenerate(idx+1, ans, ds, nums);
        ds.pop_back();

        subsetgenerate(idx+1, ans, ds, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        subsetgenerate(0, ans, ds, nums);
        return ans;
    }
};

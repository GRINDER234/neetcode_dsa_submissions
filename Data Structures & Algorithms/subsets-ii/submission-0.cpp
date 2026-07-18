class Solution {
public:
    void backtrack_permute(int i, vector<vector<int>>&res, vector<int>&ans, vector<int>&nums){
        res.push_back(ans);
        for(int idx = i; idx < nums.size(); idx++){
            if(idx > i && nums[idx] == nums[idx-1]) continue;
            ans.push_back(nums[idx]);
            backtrack_permute(idx+1, res, ans, nums);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>ans;
        backtrack_permute(0, res, ans, nums);
        return res;
    }
};

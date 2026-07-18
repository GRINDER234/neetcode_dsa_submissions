class Solution {
public:
    void backtrack_permute(vector<int>&nums, vector<bool>&pick, vector<int>&ans, vector<vector<int>>&res){
        if(ans.size() == nums.size()){
            res.push_back(ans);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!pick[i]){
                pick[i] = true;
                ans.push_back(nums[i]);
                backtrack_permute(nums, pick, ans, res);
                pick[i] = false;
                ans.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        vector<bool>pick(nums.size(), false);
        backtrack_permute(nums, pick, ans, res);
        return res;
    }
};

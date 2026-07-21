class Solution {
public:
    void backtrack_combination(int i, vector<vector<int>>&ans, vector<int>&res, vector<int>&candidates, int target){
        if(target == 0){
            ans.push_back(res);
            return;
        }

        if(i == candidates.size()) return;

        if(candidates[i] <= target){
            res.push_back(candidates[i]);
            backtrack_combination(i+1, ans, res, candidates, target-candidates[i]);
            res.pop_back();
        }

        while(i+1 < candidates.size() && candidates[i+1] == candidates[i]){
            i=i+1;
        }

        backtrack_combination(i+1, ans, res, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>res;
        backtrack_combination(0, ans, res, candidates, target);
        return ans;
    }
};

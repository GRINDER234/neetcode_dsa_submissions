class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i=0; i<nums.size(); ++i){
            set<int>hshset;
            for(int j=i+1; j<nums.size(); ++j){
                 if(hshset.find(-nums[i] - nums[j]) != hshset.end()){
                    vector<int>temp = {nums[i], nums[j], -nums[i]-nums[j]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                 }
                 hshset.insert(nums[j]);
            }
        }

        for(auto it : s){
            ans.push_back(it);
        }

        return ans;
    }
};

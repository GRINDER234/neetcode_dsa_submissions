class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        for(auto i : nums){
            mpp[i]++;
        }

        vector<int>ans;
        for(auto it : mpp){
            if(it.second >= k) ans.push_back(it.first);
        }

        return ans;
    }
};

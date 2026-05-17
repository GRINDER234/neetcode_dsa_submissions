class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        for(auto i : nums){
            mpp[i]++;
        }

        vector<vector<int>>buckets(nums.size() + 1);
        for(auto it : mpp){
            buckets[it.second].push_back(it.first);
        }

        vector<int>ans;
        for(int i=nums.size(); i>=0 && ans.size() < k; --i){
            for(int num : buckets[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }

        return ans;
    }
};

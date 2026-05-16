class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mpp;
        vector<int>idxs;
        for(int i=0; i<nums.size(); ++i){
            int key = nums[i];
            int rem = target - key;
            if(mpp.find(rem) == mpp.end()){
                mpp[key] = i;
            }else{
                idxs.push_back(i);
                idxs.push_back(mpp[rem]);
                break;
            }
        }

        if(idxs[0] > idxs[1]){
            swap(idxs[0], idxs[1]);
            return idxs;
        }else{
            return idxs;
        }
    }
};

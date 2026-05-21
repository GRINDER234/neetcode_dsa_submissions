class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        if(n == 0) return 0;
        for(int el : nums){
            st.insert(el);
        }
        
        int maxseqlt = 1;
        for(int el : st){
            if(st.find(el-1) != st.end()) continue;
            int x = el, cnt = 1;
            x = x + 1;
            while(st.find(x) != st.end()){
                cnt++;
                x = x + 1;
            }
            maxseqlt = max(maxseqlt, cnt);
            cnt = 0;
        }

        return maxseqlt;
    }
};

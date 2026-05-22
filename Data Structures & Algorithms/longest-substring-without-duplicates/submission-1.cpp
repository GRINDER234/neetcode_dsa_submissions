class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 1;
        if(s.size() == 0) return 0;
        unordered_set<char>st;
        while(r < s.size()){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            res = max(res, r-l+1);
            r++;
        }

        return res;
    }
};

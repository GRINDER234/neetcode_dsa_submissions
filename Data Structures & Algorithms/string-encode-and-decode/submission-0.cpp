class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs) ans += to_string(s.size()) + "/:" + s;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;
        while(i < s.size()){
            int len = 0;
            while(i < s.size() && !(s[i] == '/' && i + 1 < s.size() && s[i+1] == ':')){
                len = len * 10 + (s[i] - '0');
                i++;
            }
            
            i = i + 2;
            
            string curr_str = "";
            for(int k=0; k<len; ++k){
                curr_str = curr_str + s[i];
                i++;
            }
            
            ans.push_back(curr_str);
        }
        
        return ans;
    }
};

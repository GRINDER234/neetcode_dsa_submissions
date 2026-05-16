class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int>hsh_s(26, 0);
        vector<int>hsh_t(26, 0);

        for(int i=0; i<s.size(); ++i){
            hsh_s[s[i] - 'a']++;
        }

        for(int i=0; i<t.size(); ++i){
            hsh_t[t[i] - 'a']++;
        }

        int flag = 0;
        for(int i=0; i<26; ++i){
            if(hsh_s[i] != hsh_t[i]){
                flag = 1;
                break;
            }
        }

        if(flag == 0) return true;
        return false;
    }
};

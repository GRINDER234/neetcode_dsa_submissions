class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int>hasht(256, 0);

        for(int i=0; i<m; ++i){
            hasht[t[i]]++;
        }

        int minlen = INT_MAX, l = 0, r = 0, cnt = 0, sindx = -1;

        while(r < s.size()){
            if(hasht[s[r]] > 0) cnt = cnt + 1;
            hasht[s[r]]--;

            while(cnt == m){
                if(r - l + 1 < minlen){
                    minlen = r-l+1;
                    sindx = l;
                }
                hasht[s[l]]++;
                if(hasht[s[l]] > 0) cnt = cnt - 1;
                l = l + 1;
            }

            r = r + 1;
        }

        return sindx == -1 ? "" : s.substr(sindx, minlen);

    }
};

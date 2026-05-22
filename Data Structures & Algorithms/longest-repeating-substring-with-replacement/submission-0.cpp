class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int n = s.size(), l = 0;
        int maxlen = 0, maxfreq = 0;
        for(int r = 0; r < n; ++r){
            v[s[r] - 'A']++;
            maxfreq = max(maxfreq, v[s[r] - 'A']);

            while((r-l+1) - maxfreq > k)
            {
                v[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, (r-l+1));
        }

        return maxlen;
    }
};

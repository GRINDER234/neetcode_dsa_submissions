class Solution {
public:
    bool checkFreqvec(vector<int> &v1, vector<int> &v2)
    {
        for(int i=0; i<26; ++i){
            if(v1[i] != v2[i]){
                return false;
            }
        }

        return true;
    }


    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int>hash(26, 0);
        
        for(int i=0; i<n1; ++i){
            hash[s1[i] - 'a']++;
        }

        int windsize = s1.size();
        for(int i=0; i<n2; ++i){
            int windidx = 0, idx = i;
            
            vector<int>freqwind(26, 0);
            while(windidx < windsize && idx < n2){
                freqwind[s2[idx] - 'a']++;
                windidx++; idx++;
            }

            if(checkFreqvec(hash, freqwind)){
                return true;
            }
        }

        return false;
        
    }
};

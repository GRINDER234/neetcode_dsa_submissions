class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // TC:O(NKlogK) SC:O(N*K)
        // vector<vector<string>>ans;
        // unordered_map<string, vector<string>>umap;

        // for(auto x : strs){
        //     string temp = x;
        //     sort(x.begin(), x.end());
        //     umap[x].push_back(temp);
        // }

        // for(auto it : umap){
        //     ans.push_back(it.second);
        // }


        
        unordered_map<string, vector<string>>umap;
        for(auto x : strs){
            vector<int>count(26, 0);
            for(char c : x){
                count[c - 'a']++;
            }

            string soumya = "";
            for(int i=0; i<26; ++i){
                soumya += to_string(count[i]) + "#";
            }
            umap[soumya].push_back(x);
        }

        vector<vector<string>>ans;
        for(auto it : umap){
            ans.push_back(it.second);
        }

        return ans;
    }
};

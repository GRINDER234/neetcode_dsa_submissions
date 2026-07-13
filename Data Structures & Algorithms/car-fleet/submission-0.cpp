class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>pr;
        for(int i=0; i<position.size(); i++){
            pr.push_back({position[i], speed[i]});
        }

        sort(pr.begin(), pr.end());
        vector<double>v;
        for(int i=pr.size() - 1; i>=0; --i){
            v.push_back((double)(target - pr[i].first) / pr[i].second);
            if(v.size() >= 2 && v.back() <= v[v.size() - 2]){
                v.pop_back();
            }
        }

        return v.size();
    }
};

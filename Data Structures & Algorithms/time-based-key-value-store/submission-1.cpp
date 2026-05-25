class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timeRegistry;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeRegistry[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timeRegistry.find(key) == timeRegistry.end()) return "";

        const auto& ref = timeRegistry[key];

        int lo = 0;
        int hi = ref.size() - 1;
        int ans = -1;

        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(ref[mid].first <= timestamp){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        if(ans == -1) return "";
        return ref[ans].second;
    }
};
